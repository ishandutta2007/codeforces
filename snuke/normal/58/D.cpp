#include <cstdio> 
#include <vector> 
#include <string> 
#include <stack> 
#include <queue> 
#include <set> 
#include <map> 
#include <deque> 
#include <algorithm> 
#include <cmath> 
#include <string.h> 
#define rep(i,n) for(int i=0; i<n; i++) 
#define rrep(i,o,n) for(int i=o; i<n; i++) 
#define drep(i,o,n) for(int i=o; i>n; i--) 
#define pb push_back 
using namespace std; 

priority_queue<string, vector<string>, greater<string> > s[11]; 

int main () { 
	int n, l = 0, c;
	char a[13];
	string b, g; 
	scanf("%d",&n); 
	
	rep(i,n){ 
		scanf("%s",a);
		b = a;
		s[b.size()].push(b); 
		l += b.size(); 
	} 
	
	l = l*2/n; 
	
	scanf("%s",a); 
	
	if (a[0] < 'a') { 
		rep(j,n/2){ 
			b = "|"; 
			rrep(i,1,11){ 
				if (!s[i].empty()) {
					g = s[i].top();
					b = min(b, g); 
				} 
			} 
			c = b.size(); s[c].pop(); g = s[l-c].top();
			printf("%s%c%s\n",b.c_str(),a[0],g.c_str()); 
			s[l-c].pop(); 
		} 
	} else { 
		rep(j,n/2){ 
			b = "|"; 
			rrep(i,1,11){ 
				if (!s[i].empty()) { 
					g = s[i].top();
					rep(k,b.size()){
						if (b[k] < g[k]) break; 
						if (b[k] > g[k]){b = g;break;} 
						if (k == b.size()-1){b = g; break;} 
					} 
				} 
			} 
			c = b.size(); s[c].pop(); g = s[l-c].top();
			printf("%s%c%s\n",b.c_str(),a[0],g.c_str()); 
			s[l-c].pop(); 
		}
	} 
	return 0; 
}