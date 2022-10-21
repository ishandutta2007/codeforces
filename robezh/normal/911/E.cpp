#include <bits/stdc++.h>
using namespace std;

int n,k;
int num[200050];
stack<int> S;
int now = 1;
vector<int> res;

int main() {
    cin >> n >> k;
    for(int i = 0; i < k; i++) cin >> num[i];
    int pos = 0;
    while(pos < k){
        if(S.empty() || num[pos] < S.top()){
            S.push(num[pos]);
            while(!S.empty() && S.top() == now){
                S.pop();
                now++;
            }
            pos++;
        }
        else{
            return !printf("-1");
        }
    }
    while(res.size() < n - k){
        for(int i = (S.empty() ? n : S.top() - 1); i >= now; i--){
            res.push_back(i);
        }
        now = S.empty() ? n + 1 : S.top() + 1;
        S.pop();
    }
    for(int i = 0; i < k; i++) cout << num[i] << " ";
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";

}