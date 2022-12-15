#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }

int n, k;

int arr[7]{1, 6, 4, 2, 3, 5, 4};

int q_or(int i, int j){
    //return arr[i] | arr[j];
    ++i, ++j;
    cout << "or " << i << " " << j << "\n";
    cout.flush();
    int ret;
    cin >> ret;
    return ret;
}

int q_and(int i, int j){
    //return arr[i] & arr[j];
    ++i, ++j;
    cout << "and " << i << " " << j << "\n";
    cout.flush();
    int ret;
    cin >> ret;
    return ret;
}

void q_answer(int answer){
    cout << "finish " << answer << "\n";
    cout.flush();
    exit(0);
}

const int N = 1e4 + 3;
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    int b_or[3]{}, b_and[3]{};
    for(int i = 0; i < 3; ++i)
        for(int j = i + 1; j < 3; ++j){
            int t_or = q_or(i, j), t_and = q_and(i, j);
            for(int bit = 0; bit < 30; ++bit){
                if(!(t_or & (1 << bit))){
                    b_or[i] |= 1 << bit;
                    b_or[j] |= 1 << bit;
                }
                if(t_and & (1 << bit)){
                    b_and[i] |= 1 << bit;
                    b_and[j] |= 1 << bit;
                }
            }
        }

    for(int i = 0; i < 30; ++i){
        int bit = (1 << i);
        if((b_or[0] & bit) || (b_or[1] & bit) || (b_or[2] & bit)){
            for(int j = 0; j < 3; ++j){
                if(b_or[j] & bit) continue;
                else a[j] += bit;
            }
        }
        else{
            for(int j = 0; j < 3; ++j){
                if(b_and[j] & bit) a[j] += bit;
                else continue;
            }
        }
    }

    for(int i = 3; i < n; ++i){
        int t_or, t_and;
        t_or = q_or(0, i);
        t_and = q_and(0, i);
        for(int bit = 0; bit < 30; ++bit){
            if(a[0] & (1 << bit)){
                if(t_and & (1 << bit)) a[i] += 1 << bit;
            }
            else{
                if(t_or & (1 << bit)) a[i] += 1 << bit;
            }
        }
    }

    sort(a, a + n);
    q_answer(a[k - 1]);
}