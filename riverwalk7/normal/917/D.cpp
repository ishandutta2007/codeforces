#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define db long double
#define ii pair<int,int>
#define vi vector<int>
#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define FN(i, n) for (int i = 0; i < (int)(n); ++i)
#define FEN(i,n) for (int i = 1;i <= (int)(n); ++i)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repv(i,a,b) for(int i=b-1;i>=a;i--)
#define SET(A, val) memset(A, val, sizeof(A))
typedef tree<int ,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set ;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
// Gauss-Jordan elimination solves (AX = B). O(n^3)
// INPUT: a[][] = an nxn matrix, b[][] = an nxm matrix
// OUTPUT: X= an nxm matrix (stored in b[][])
//A^{-1} = an nxn matrix (stored in a[][])
//returns determinant of a[][]
const int mod=1e9+7,N=105;
int add(int x,int y)
{
  x+=y;
  if(x>=mod) x-=mod;
  if(x<0) x+=mod;
  return x;
}
int mult(int x,int y)
{
  ll tmp=(ll)x*y;
  if(tmp>=mod) tmp%=mod;
  if(tmp<0) tmp+=mod;
  return tmp;
}
int pow1(int x,int y)
{
  int ans=1;
  while(y)
    {
      if(y&1) ans=mult(ans,x);
      x=mult(x,x); y>>=1;
    }
  return ans;
}
int inv(int x)
{
  return pow1(x,mod-2);
}
void swap_rows(vector<vi> &mat,int i1,int j1)
{
  int n=sz(mat[0]);
  rep(i,0,n)
    swap(mat[i1][i],mat[j1][i]);
}
int GaussJordan(vector<vi> &mat)
{
  int n=sz(mat[0]);
  bool is_neg=false;
  rep(i,0,n)
    {
      int rr=-1;
      rep(j,i,n)
	{
	  if(mat[j][i])
	    {
	      rr=j;
	      break;
	    }
	}
      if(rr==-1) return 0;
      if(rr!=i)
	{
	  is_neg=!is_neg;
	  swap_rows(mat,rr,i);
	}
      int the_inv=inv(mat[i][i]);
      rep(j,i+1,n)
	{
	  int fact= mult(the_inv,mat[j][i]);
	  rep(k,i,n)
	    mat[j][k]=add(mat[j][k],-mult(fact,mat[i][k]));
	}
    }
  int ans=1;
  rep(i,0,n)
    ans=mult(ans,mat[i][i]);
  if(is_neg) ans=add(0,-ans);
  return ans;
}
int w[N][N],b[N][N],val[N],poly[N],tmppoly[N],currpoly[N];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(NULL) ; cout.tie(NULL) ;
  int n,x,y;
  cin>>n;
  rep(i,1,n)
    {
      cin>>x>>y; x--; y--;
      b[x][y]=b[y][x]=1;
    }
  rep(i,0,n) rep(j,0,n)
    {
      if(i==j) continue;
      if(!b[i][j]) w[i][j]=1;
    }
  rep(i,0,n)
    {
      vector<vi> tmp(n,vi(n,0));
      vector<vi> v(n-1,vi(n-1,0));
      rep(j,0,n)
	rep(k,j+1,n)
	{
	  tmp[j][k]=add(0,-add(mult(b[j][k],i),w[j][k]));
	  tmp[k][j]=tmp[j][k];
	  tmp[j][j]=add(tmp[j][j],-tmp[j][k]);
	  tmp[k][k]=add(tmp[k][k],-tmp[k][j]);
	}
      rep(j,0,n-1)
	rep(k,0,n-1)
	v[j][k]=tmp[j][k];
      val[i]=GaussJordan(v);
    }
  rep(i,0,n)
    {
      rep(j,0,n) currpoly[j]=0;
      int den=1;
      currpoly[0]=1;
      rep(j,0,n)
	{
	  if(i==j) continue;
	  rep(k,0,n) tmppoly[k]=0;
	  rep(k,0,n) tmppoly[k+1]=currpoly[k];
	  rep(k,0,n) tmppoly[k]=add(tmppoly[k],-mult(j,currpoly[k]));
	  rep(k,0,n) currpoly[k]=tmppoly[k];
	  den=mult(den,add(0,i-j));
	}
      den=mult(inv(den),val[i]);
      rep(j,0,n) poly[j]=add(poly[j],mult(currpoly[j],den));
    }
  rep(i,0,n) cout<<poly[i]<<" ";
  cout<<endl;
  return 0 ;
}