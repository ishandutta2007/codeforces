#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Line{
    int a, b;
    int index;

    Line(){}
    Line(int a, int b, int index){
        this->a = a;
        this->b = b;
        this->index = index;
    }
};

struct Convex_Hull_Trick{
    vector<Line> lines;

    Convex_Hull_Trick(){}

    bool is_better(const Line &line_1, const Line &line_2, long long time){
        return line_1.a + line_1.b * time > line_2.a + line_2.b * time;
    }

    int size()const{
        return lines.size();
    }

    Line operator[](int index)const{
        return lines[index];
    }

    long double get_intersection(const Line &line_1, const Line &line_2){
        return (long double)(line_2.a - line_1.a) / (long double)(line_1.b - line_2.b);
    }

    void insert(Line line){
        while(lines.size() >= 2){
            if(lines.back().b == line.b){
                if(lines.back().a > line.a)
                    swap(lines.back(), line);
                lines.pop_back();
                continue;
            }

            long double x1 = get_intersection(lines.back(), line);
            long double x2 = get_intersection(lines.back(), lines[lines.size() - 2]);

            /*cout << endl;
            cout << lines[lines.size() - 2].a << "," << lines[lines.size() - 2].b << endl;
            cout << line.a << "," << line.b << endl;
            cout << lines.back().a << "," << lines.back().b << endl;
            cout << x1 << " x1 " << endl;
            cout << x2 << " x2 " << endl;*/

 
            if(x1 > x2)
                break;
            else
                lines.pop_back();
        }

        if(!lines.empty()){
            if(line.b == lines.back().b){
                if(lines.back().a > line.a)
                    swap(lines.back(), line);
                lines.pop_back();
            }
        }

        lines.push_back(line);
    }

    friend Convex_Hull_Trick merge(const Convex_Hull_Trick &l_value, const Convex_Hull_Trick &r_value){
        int l_ptr = 0, r_ptr = 0;
        vector<Line> sorted_lines;

        while(l_ptr != l_value.size() && r_ptr != r_value.size()){
            if(l_value[l_ptr].b < r_value[r_ptr].b){
                sorted_lines.push_back(l_value[l_ptr]);
                l_ptr++;
            }
            else{
                sorted_lines.push_back(r_value[r_ptr]);
                r_ptr++;
            }
        }

        while(l_ptr != l_value.size()){
            sorted_lines.push_back(l_value[l_ptr]);
            l_ptr++;
        }

        while(r_ptr != r_value.size()){
            sorted_lines.push_back(r_value[r_ptr]);
            r_ptr++;
        }

        Convex_Hull_Trick answer;
        for(const Line &line: sorted_lines)
            answer.insert(line);

        return answer;
    }

    pair<long long, int> get_maximum(long long time){
        int l = 0, r = (int)lines.size() - 1;
        while(l != r){
            int mid = (l + r) >> 1;

            if(is_better(lines[mid], lines[mid + 1], time))
                r = mid;
            else
                l = mid + 1;
        }

        return {lines[l].a + time * lines[l].b, lines[l].index};
    }
};

template<size_t t_N>
struct Segment_Tree{
    Convex_Hull_Trick nodes[4 * t_N];
    static const long long k_Inf = 1e18;

    Segment_Tree(){}

    void build(int index, int l, int r, pair<int, int> p[]){
        if(l == r){
            nodes[index] = Convex_Hull_Trick();
            nodes[index].insert({p[l].first, p[l].second, l});
            return;
        }

        int mid = (l + r) >> 1;
        build(2 * index + 1, l, mid, p);
        build(2 * index + 2, mid + 1, r, p);
    
        nodes[index] = merge(nodes[2 * index + 1], nodes[2 * index + 2]);

        //cout << "nodes[" << index << "]: ";
        //for(Line &line: nodes[index].lines)
        //    cout << line.a << "," << line.b << " ";
        //cout << endl; 
    }

    pair<long long, int> query(int index, int l, int r, int sl, int sr, int time){
        if(l > sr || r < sl)
            return {-k_Inf, -1};
        if(sl <= l && r <= sr)
            return nodes[index].get_maximum(time);

        int mid = (l + r) >> 1;
        pair<long long, int> l_value = query(2 * index + 1, l, mid, sl, sr, time);
        pair<long long, int> r_value = query(2 * index + 2, mid + 1, r, sl, sr, time);

        return max(l_value, r_value);
    }
};

const int k_N = 1e5 + 7;

int n, q;
pair<int, int> p[k_N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> p[i].first >> p[i].second;

    static Segment_Tree<k_N> segment_tree;
    segment_tree.build(0, 1, n, p);

    for(int i = 0; i < q; ++i){
        int l, r, t;
        cin >> l >> r >> t;

        cout << segment_tree.query(0, 1, n, l, r, t).second << "\n";
    }
}
/*
4 0
40 18
24 37
41 35
49 11
*/