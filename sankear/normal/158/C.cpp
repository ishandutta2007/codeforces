#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

#define pb push_back
#define ppb pop_back

int main(){
    //freopen("rifleman.in", "r", stdin);
    //freopen("rifleman.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector <string> path;
	for(int i = 0; i < n; i++){
		string cmd;
		cin >> cmd;
		if(cmd == "pwd"){
			cout << "/";
			for(int j = 0; j < (int)path.size(); j++){
				cout << path[j] << "/";
			}
			cout << endl;
			continue;
		}
		string go;
		cin >> go;
		if(go[0] == '/'){
			path.clear();
			go = go.substr(1, go.length() - 1);
		}
		vector <string> cmds;
		string cur = "";
		for(int j = 0; j < (int)go.length(); j++){
			if(go[j] == '/'){
				if((int)cur.length() > 0){
					cmds.pb(cur);
				}
				cur = "";
				continue;
			}
			cur += go[j];
		}
		if((int)cur.length() > 0){
			cmds.pb(cur);
		}
		for(int j = 0; j < (int)cmds.size(); j++){
			if(cmds[j] == ".."){
				path.ppb();
			}
			else{
				path.pb(cmds[j]);
			}
		}
	}
	return 0;
}