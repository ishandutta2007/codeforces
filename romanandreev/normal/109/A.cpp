#include<cmath>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
#include<cassert>
#include<ctime>
#include<climits>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define y1 y1_fudisghsdis
#define y0 y0_fudisghsdis
#define ws ws_fudisghsdis
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
#define uniq(a) {sort(all(a));(a).resize(unique(all(a))-(a).begin());}
#define uniq1(a,n) {sort(a,a+n);n=unique(a,a+n)-a;}

typedef pair<int,int> pi;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

#ifdef WIN32 
	#define INT64 "%I64d"
#else
	#define INT64 "%lld"	
#endif

int main(){
	#ifdef home
	assert(freopen("output.txt","w",stdout));
	assert(freopen("input.txt","r",stdin));
	#endif
	int n;
	cin>>n;
	int mni;
	mni=n+1;
	for (int i=n;i>=0;i--) if (n>=i*4 && (n-i*4)%7==0){
		if (mni+(n-mni*4)/7>i+(n-i*4)/7)
		mni=min(mni,i);
	}
	if (mni!=n+1){
		for (int j=0;j<mni;j++)
			printf("4");
		for (int j=0;j<(n-mni*4)/7;j++)
			printf("7");
		printf("\n");
		return 0;
	}
	printf("-1\n");
	#ifdef home
		cerr<<clock()*1.0/CLOCKS_PER_SEC<<endl;
	#endif
	return 0;
}