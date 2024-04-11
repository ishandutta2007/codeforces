#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
const int NICO = 200002;
typedef long long ll;
ll n, k, x;
ll a[NICO];
ll res[NICO];
int cnt = 0;
struct Num
{
    ll val;
    int id;
    Num(ll val_,int id_){val=val_;id=id_;}
    Num(){}
};
struct cmp
{
    bool operator()(const Num &a,const Num &b)
    {
        return abs(a.val)<abs(b.val);
    }
};
multiset<Num,cmp> st;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k >> x;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        st.insert(Num(a[i],i));
        cnt += (a[i] < 0);
    }
    for(int i=1;i<=k;i++)
    {
        Num tmp = *st.begin();
        if(tmp.val<0) cnt--;
        st.erase(st.begin());
        if(cnt&1)
        {
            st.insert(Num(tmp.val+x,tmp.id));
            if(tmp.val+x<0) cnt++;
        } else {
            st.insert(Num(tmp.val-x,tmp.id));
            if(tmp.val-x<0) cnt++;
        }
    }
    multiset<Num,cmp>::iterator it;
    for(it = st.begin();it!=st.end();it++)        
    {
        Num tmp = *it;            
        res[tmp.id] = tmp.val;
    }
    for(int i=1;i<=n;i++)
    {
        cout << res[i];
        if(i==n) cout << endl;
        else cout << " ";
    }
}