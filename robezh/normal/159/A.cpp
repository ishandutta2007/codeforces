#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

typedef pair<string, string> P;

map<P, int> M;
map<P, int> fri;
int n,k;
vector<P> dat;
vector<int> time;
vector<P> V;

int main() {
    int n,k;
    string a,b;
    int d;
    scanf("%d%d", &n, &k);
    getchar();

    for(int i = 0; i < n; i++) {
    	cin >> a >> b >> d;
    	dat.push_back(P(a,b));
    	time.push_back(d);
    }
    
    for(int i = 0; i < n; i++){
    	P pi = dat[i];
    	for(int j = i+1; j < n; j++){
    		if(time[j] - time[i] > k) break;
    		if(time[j] - time[i] == 0) continue;
    		
    		P pj = dat[j];
    		if(pi.first == pj.second && pi.second == pj.first){
    			if(!fri.count(pi) && !fri.count(pj)){
    				V.push_back(pi);
    				fri[pi] = 1;
				}
			}
    		
		}
	}
    
    cout << V.size() << endl;
    for(int i = 0; i < V.size(); i++){
    	P p = V[i];
    	cout << p.first << " " << p.second << endl;
	}
}