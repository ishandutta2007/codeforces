#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;

int n;
int num[N];
priority_queue<int, vector<int>, greater<int> > pque;
int ans = 0;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    sort(num, num+n);
    for(int i = 0; i < n; i++){
        if(!pque.empty() && pque.top() < num[i]){
            pque.pop(); ans++;
        }
        pque.push(num[i]);
    }
    printf("%d", ans);
}