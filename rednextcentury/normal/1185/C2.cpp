#include <bits/stdc++.h>
using namespace std ;
int num[1000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> ret;
    int sum=0;
    for (int i=0;i<n;i++) {
        int x;
        cin>>x;
        sum+=x;
        int need = sum - m;
        int add=0;
        for (int j=100;j>=1;j--) {
            if (need<=0)break;
            int cnt = need / j + (need%j>0);
            if (cnt<=num[j])
            {
                add+=cnt;
                need=-1;
            }
            else {
                need -= num[j]*j;
                add+=num[j];
            }
        }
        ret.push_back(add);
        num[x]++;
    }
    for (auto x:ret)cout<<x<<' ';
    cout<<endl;
}