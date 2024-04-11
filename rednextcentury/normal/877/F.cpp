#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int SQRT = 300;
struct node
{
    int l,r,id;
} Q[1000001];
long long a[1000001];
set<long long> s;
map<long long,int> mp;
int L[1000001];
int R[1000001];
long long ans=0;
long long num1[1000001];
long long num2[1000001];
long long ret[1000001];
int64_t ord[1000000];
inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}
bool operator<(node A,node B)
{
    return ord[A.id]<ord[B.id];
}
void delL(int x)
{
    ans-=num2[R[x-1]];
    num2[a[x]]--;
    num1[a[x-1]]--;
}
void addL(int x)
{
    num2[a[x]]++;
    num1[a[x-1]]++;
    ans+=num2[R[x-1]];
}
void delR(int x)
{
    ans-=num1[L[x]];
    num2[a[x]]--;
    num1[a[x-1]]--;
}
void addR(int x)
{
    num1[a[x-1]]++;
    num2[a[x]]++;
    ans+=num1[L[x]];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    s.insert(k);
    s.insert(0);
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if (a[i]==1)a[i]=x;
        else a[i]=-x;
        a[i]=a[i-1]+a[i];
        s.insert(a[i]);
        s.insert(a[i]-k);
        s.insert(a[i]+k);
    }
    int tot=0;
    for (auto x:s)
    {
        mp[x]=tot++;
    }
    for (int i=1;i<=n;i++)
    {
        L[i] = mp[a[i]-k];
        R[i] = mp[a[i]+k];
        a[i] = mp[a[i]];
    }
    int l=1,r=0;
    int q;
    cin>>q;
    for (int i=0;i<q;i++)
        cin>>Q[i].l>>Q[i].r,Q[i].id=i,ord[i]=gilbertOrder(Q[i].l,Q[i].r,21,0);
    L[0]=-1,R[0]=mp[k];
    a[0]=mp[0];
    sort(Q,Q+q);
    for (int i=0;i<q;i++)
    {
        while(l<Q[i].l)
            delL(l++);
        while(l>Q[i].l)
            addL(--l);
        while(r<Q[i].r)
            addR(++r);
        while(r>Q[i].r)
            delR(r--);
        ret[Q[i].id]=ans;
    }
    for (int i=0;i<q;i++)
        cout<<ret[i]<<endl;
}