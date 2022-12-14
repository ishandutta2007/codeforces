#include<bits/stdc++.h>
using namespace std;
int num[10000];
int main(){
    int n;
    cin>>n;
    long long ret = 0;
    for (int i=1;i<=n;i++) {
        int x;
        cin>>x;
        int b = __builtin_popcount(x);
        ret += num[b];
        num[b]++;
    }
    cout<<ret<<endl;
}