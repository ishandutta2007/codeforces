#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// mod
const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)
typedef complex<Real> P;

int n;

bool inrect(int a,int b,int c,int d,int e,int f,int g,int h){
  // (a,b)~(c,d) contains (e,f)~(g,h)
  return (a<=e&&g<=c&&b<=f&&h<=d);
}

int query(int a,int b,int c,int d){
  assert(1<=a&&a<=c&&c<=n);
  assert(1<=b&&b<=d&&d<=n);
  printf("? %d %d %d %d\n",a,b,c,d);fflush(stdout);
  int r;
  scanf("%d",&r);
  return r;
}

bool answer(int a,int b,int c,int d,int e,int f,int g,int h){
  assert(1<=a&&a<=c&&c<=n);
  assert(1<=b&&b<=d&&d<=n);
  assert(1<=e&&e<=g&&g<=n);
  assert(1<=f&&f<=h&&h<=n);
  printf("! %d %d %d %d %d %d %d %d\n",a,b,c,d,e,f,g,h);fflush(stdout);
  return true;
}

int main(){
  scanf("%d",&n);

  int at,al,ab,ar;
  int bt,bl,bb,br;
  {
    int left = 0, right = n;
    while(left+1<right){
      int mid = (left+right)>>1;
      int a = query(1,1,mid,n);
      if(a<1)left=mid;
      else right=mid;
    }
    ar = right;
  }
  {
    int left = 1, right = ar+1;
    while(left+1<right){
      int mid = (left+right)>>1;
      int a = query(mid,1,ar,n);
      if(a<1)right=mid;
      else left=mid;
    }
    al = left;
  }
  {
    int top = 0, bottom = n;
    while(top+1<bottom){
      int mid = (top+bottom)>>1;
      int a = query(al,1,ar,mid);
      if(a<1)top=mid;
      else bottom=mid;
    }
    ab = bottom;
  }
  {
    int top = 1, bottom = ab+1;
    while(top+1<bottom){
      int mid = (top+bottom)>>1;
      int a = query(al,mid,ar,ab);
      if(a<1)bottom=mid;
      else top=mid;
    }
    at = top;
  }

  // decide b
  {
    int left = 0, right = n;
    while(left+1<right){
      int mid = (left+right)>>1;
      int a = query(1,1,mid,n);
      if(inrect(1,1,mid,n,al,at,ar,ab))--a;
      if(a<1)left=mid;
      else right=mid;
    }
    br = right;
  }
  {
    int left = 1, right = br+1;
    while(left+1<right){
      int mid = (left+right)>>1;
      int a = query(mid,1,br,n);
      if(inrect(mid,1,br,n,al,at,ar,ab))--a;
      if(a<1)right=mid;
      else left=mid;
    }
    bl = left;
  }
  {
    int top = 0, bottom = n;
    while(top+1<bottom){
      int mid = (top+bottom)>>1;
      int a = query(bl,1,br,mid);
      if(inrect(bl,1,br,mid,al,at,ar,ab))--a;
      if(a<1)top=mid;
      else bottom=mid;
    }
    bb = bottom;
  }
  {
    int top = 1, bottom = bb+1;
    while(top+1<bottom){
      int mid = (top+bottom)>>1;
      int a = query(bl,mid,br,bb);
      if(inrect(bl,mid,br,bb,al,at,ar,ab))--a;
      if(a<1)bottom=mid;
      else top=mid;
    }
    bt = top;
  }
  answer(al,at,ar,ab,bl,bt,br,bb);
  return 0;
}