// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef pair<int,int> pii;

const int maxn=2e5+10;
const int maxB=12;
const int maxM=(1<<12);

#pragma GCC Optimize("Ofast")
#pragma GCC Optimize("O3")

int a[maxB][maxn];
int t[maxn],x[maxn],y[maxn];

bool b[maxM][maxn];

int main(){
    int n,k,q;scanf("%d%d%d",&n,&k,&q);
    REP(i,k){
	REP(j,n){
	    scanf("%d",&a[i][j]);
	}
    }
    REP(i,q){
	scanf("%d%d%d",&t[i],&x[i],&y[i]);
	x[i]--;y[i]--;
    }
    
    REP(msk,maxM){
	REP(i,k){
	    b[msk][i]=bit(msk,i);
	}
	int h=k;
	REP(i,q){
	    if(t[i]==1)
		b[msk][h++]=b[msk][x[i]]|b[msk][y[i]];
	    if(t[i]==2)
		b[msk][h++]=b[msk][x[i]]&b[msk][y[i]];
	}
    }

    REP(i,q){
	if(t[i]==3){
	    vector<pii>vec;
	    vec.clear();
	    REP(j,k){
		vec.PB(MP(a[j][y[i]],j));
	    }
	    sort(vec.begin(),vec.end());

	    int msk=0;
	    REPD(j,k){
		msk|=(1<<vec[j].S);
		if(b[msk][x[i]]){
		    printf("%d\n",vec[j].F);
		    break;
		}
	    }	
	}
    }
}