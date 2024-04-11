#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[1000000];
int n;
bool Rem(int x,int d) {
    int last=-1;
    for (int i=0;i<n;i++) {
        if (i==x)continue;
        if (last!=-1 && a[i].first-a[last].first!=d) {
            return 0;
        }
        last=i;
    }
    return 1;
}
int Try(int x) {
    for (int i=1;i<n;i++) {
        if (a[i].first-a[i-1].first!=x) {
            if (Rem(i,x))return i;
            else if (Rem(i-1,x))return i-1;
            else return -1;
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i].first,a[i].second=i+1;
    sort(a,a+n);
    if (n<=3) {
        cout<<1<<endl;
        return 0;
    }
    int l = Try(a[1].first-a[0].first);
    int r = Try(a[2].first-a[0].first);
    int k = Try(a[2].first-a[1].first);
    if (max(l,max(r,k))!=-1)
        cout<<a[max(l,max(r,k))].second<<endl;
    else cout<<-1<<endl;
}