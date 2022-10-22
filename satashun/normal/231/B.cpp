//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int main(){
    int n,d,l,i,min,max,diff_min,diff,flag;
    scanf("%d%d%d",&n,&d,&l);
    
    switch(n % 2){
	case 1:
	    min=(n+1)/2-l*(n-1)/2;
	    max=l*(n+1)/2-(n-1)/2;
	    if((d<min)||(d>max)) printf("-1\n");
	    else{
		diff_min=(l-1)*(n-1)/2;
		diff=(d-min);
		flag=0;
		if(diff<=diff_min){
		    for(i=0;i<n;i++){
			if(i%2){
			    if(!flag)
				if(diff<=l-1){
				    printf("%d ",l-diff);
				    flag=1;    
				}
				else{
				    printf("1 ");
				    diff-=(l-1);
				}
			    else printf("%d ",l);
			}else printf("1 ");
		    }
		}else{
		    diff=max-d;
		    flag=0;
		    for(i=0;i<n;i++){
			if(i%2==0){
			    if(!flag)
				if(diff<=l-1){
				    printf("%d ",l-diff);
				    flag=1;          
				}
				else{
				    printf("1 ");
				    diff-=(l-1);
				}
			    else
				printf("%d ",l);
			}
			else
			    printf("1 ");
		    } 
		}
	    }
	    break;
                   
	case 0:
	    min=(n)/2-l*(n)/2;
	    max=l*(n)/2-(n)/2;
	    if((d<min)||(d>max))
		printf("-1\n");
	    else{
		diff_min=(l-1)*(n)/2;
		diff=(d-min);
		flag=0;
		if(diff<=diff_min){
		    for(i=0;i<n;i++){
			if(i%2){
			    if(!flag)
				if(diff<=l-1){
				    printf("%d ",l-diff);
				    flag=1;          
				}else{
				    printf("1 ");
				    diff-=(l-1);
				}
				else printf("%d ",l);
			}
			else printf("1 ");
		    }
		}else{
		    diff=max-d;
		    flag=0;
		    for(i=0;i<n;i++){
			if(i%2==0){
			    if(!flag)
				if(diff<=l-1){
				    printf("%d ",l-diff);
				    flag=1;          
				}else
				{
				    printf("1 ");
				    diff-=(l-1);
				}
				else
				    printf("%d ",l);
			}else
			    printf("1 ");
		    }              
		}
	    }
	    break;             
    }
    return 0;
}