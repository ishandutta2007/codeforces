#include <bits/stdc++.h>

using namespace std;

float time_passed();

template<size_t t_Size>
struct Segment_Tree{
    static const int k_Inf = 1e9;
    int arr[4 * t_Size];
    int n;

    Segment_Tree(){}

    void initialise(int index, int l, int r){
        if(l == r){
            arr[index] = k_Inf;
            return;
        }

        int mid = (l + r) >> 1;
        initialise(2 * index + 1, l, mid);
        initialise(2 * index + 2, mid + 1, r);

        arr[index] = k_Inf;
    }

    void resize(int n){
        this->n = n;
        initialise(0, 0, n - 1);
    }

    void update(int index, int l, int r, int update_index, int update_value){
        if(update_index < l || r < update_index)
            return;
        if(l == r){
            arr[index] = update_value;
            return;
        }

        int mid = (l + r) >> 1;
        update(2 * index + 1, l, mid, update_index, update_value);
        update(2 * index + 2, mid + 1, r, update_index, update_value);

        arr[index] = min(arr[2 * index + 1], arr[2 * index + 2]);
    }

    void update(int update_index, int update_value){
        update(0, 0, n - 1, update_index, update_value);
    }

    pair<int, int> query_right(int index, int l, int r, int start, int value){
        if(start > r)
            return {value, r};
        if(arr[index] >= value)
            return {value, r};
        if(l == r)
            return {-1, l - 1};

        int mid = (l + r) >> 1;

        pair<int, int> answer_left = query_right(2 * index + 1, l, mid, start, value);
        if(answer_left.first < value)
            return answer_left;

        return query_right(2 * index + 2, mid + 1, r, start, value);
    }

    int query_right(int start, int value){
        if(start >= n)
            return start - 1;
        return query_right(0, 0, n - 1, start, value).second;
    }

    pair<int, int> query_left(int index, int l, int r, int start, int value){
        if(start < l)
            return {value, l};
        if(arr[index] >= value)
            return {value, l};
        if(l == r)
            return {-1, r + 1};

        int mid = (l + r) >> 1;

        pair<int, int> answer_right = query_left(2 * index + 2, mid + 1, r, start, value);
        if(answer_right.first < value)
            return answer_right;

        return query_left(2 * index + 1, l, mid, start, value);
    }

    int query_left(int start, int value){
        if(start <= -1)
            return start + 1;
        return query_left(0, 0, n - 1, start, value).second;
    }
};

template<size_t t_Size, size_t t_Log_Size, size_t t_Alphabet_Size>
struct Suffix_Array{
    int n, log_n;

    int c[t_Log_Size][t_Size], pn[t_Size], p[t_Size];
    int cnt[t_Alphabet_Size];

    Segment_Tree<t_Size> segment_tree;

    Suffix_Array(){}

    void build_segment_tree(){
        segment_tree.resize(n - 1);
        for(int i = 0; i < n - 1; ++i)
            segment_tree.update(i, lcp(p[i], p[i + 1]));
    }

    void build_suffix_array(const vector<int> &v){
        n = (int)v.size();
        log_n = 0;

        fill(cnt, cnt + t_Alphabet_Size, 0);

        for(int i = 0; i < n; ++i)
            cnt[v[i]]++;
        for(int i = 1; i < t_Alphabet_Size; ++i)
            cnt[i] += cnt[i - 1];
        for(int i = n - 1; i >= 0; --i)
            p[--cnt[v[i]]] = i;

        int classes = 1;
        c[0][p[0]] = 0;

        for(int i = 1; i < n; ++i){
            if(v[p[i]] != v[p[i - 1]])
                ++classes;
            c[0][p[i]] = classes - 1;
        }

        for(int step = 1, h = 1; h < n; h <<= 1, ++step){
            log_n = step;

            for(int i = 0; i < n; ++i){
                pn[i] = p[i] - h;
                if(pn[i] < 0)
                    pn[i] += n;
            }

            fill(cnt, cnt + classes, 0);

            for(int i = 0; i < n; ++i)
                cnt[c[step - 1][pn[i]]]++;
            for(int i = 1; i < classes; ++i)
                cnt[i] += cnt[i - 1];
            for(int i = n - 1; i >= 0; --i)
                p[--cnt[c[step - 1][pn[i]]]] = pn[i];

            classes = 1;
            c[step][p[0]] = 0;

            for(int i = 1; i < n; ++i){
                pair<int, int> previous{c[step - 1][p[i - 1]], c[step - 1][(p[i - 1] + h) % n]};
                pair<int, int> current{c[step - 1][p[i]], c[step - 1][(p[i] + h) % n]};

                if(previous != current)
                    ++classes;
                c[step][p[i]] = classes - 1;
            }
        }
    }

    void initialise(const vector<int> &v){
        build_suffix_array(v);
        build_segment_tree();
    }

    int& operator[](int index){
        return p[index];
    }

    int lcp(int i, int j){
        int answer = 0;
        for(int k = log_n; k >= 0; --k){
            if(c[k][i] == c[k][j]){
                answer += (1 << k);
                i += (1 << k);
                j += (1 << k);
            }
        }
        return answer;
    }
};

const int k_N = 2e5 + 7;
const int k_Log_N = 20;
const int k_Alphabet = k_N + 3000;

int n, k;
string a[k_N];

vector<int> v, index_in_a, index_in_string;
Suffix_Array<2 * k_N, k_Log_N, k_Alphabet> suffix_array;

int L[2 * k_N];

clock_t timer = clock();
float time_passed(){
    return (((float)clock() - (float)timer) / (float)CLOCKS_PER_SEC);
}

void find_answer(){
    int sz = v.size();

    static long long answer[k_N];
    for(int i = 0; i < sz; ++i){
        int index = suffix_array[i];

        if(index_in_a[index] == -1)
            continue;

        int l = 0, r = a[index_in_a[index]].size() - index_in_string[index];
        while(l != r){
            int mid = (l + r + 1) >> 1;

            int left_value = suffix_array.segment_tree.query_left(i - 1, mid);
            int right_value = suffix_array.segment_tree.query_right(i, mid) + 1;

            if(L[left_value] <= right_value)
                l = mid;
            else
                r = mid - 1;
        }

        answer[index_in_a[index]] += l;
    }

    for(int i = 0; i < n; ++i)
        cout << answer[i] << " ";
    cout << "\n";
}

void build_L(){
    int sz = v.size();

    static map<int, int> mp;
    int ptr = -1, cnt_different = 0;
    for(int i = 0; i < sz; ++i){
        if(i){
            int curr = index_in_a[ suffix_array[i - 1] ];
            if(curr != -1){
                if(mp[curr] == 1)
                    cnt_different--;
                mp[curr]--;
            }
        }

        while(ptr != sz - 1 && cnt_different < k){
            int curr = index_in_a[ suffix_array[++ptr] ];
            if(curr != -1){
                if(!mp[curr])
                    cnt_different++;
                mp[curr]++;
            }
        }

        if(cnt_different >= k)
            L[i] = ptr;
        else
            L[i] = sz + 1;
    }
}

void output_suffix_array(){
    cout << "suffix_array: ";
    for(int i = 0; i < v.size(); ++i)
        cout << suffix_array[i] << " ";
    cout << "\n";
}

void build_suffix_array(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < a[i].size(); ++j){
            char c = a[i][j];

            v.push_back((int)c + k_N);
            index_in_a.push_back(i);
            index_in_string.push_back(j);
        }
        v.push_back(i);
        index_in_a.push_back(-1);
        index_in_string.push_back(-1);
    }

    suffix_array.initialise(v);
}

void solve(){
    build_suffix_array();
    //output_suffix_array();
    build_L();
    find_answer();
}

void read(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
}

int main(){
    read();
    solve();
}