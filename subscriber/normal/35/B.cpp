#include <iostream>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <memory.h>
#include <math.h>
#include <time.h>

using namespace std;

int n,m,k,o,xx[10000],yy[10000],q=0,f[100][100],x,y;
string s;
map<string,int> mm;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n >> m >> k;
	for (int i=0;i<3333;i++)xx[i]=-1;
	for (int i=0;i<3333;i++)yy[i]=-1;
	for (int i=0;i<k;i++){
		cin >> o;
		if (o>0){
			cin >> x >> y >> s;
			while (f[x][y]&&x<=n){
				y++;
				if (y>m){
					y=1;
					x++;
				}
			}
			if (!mm[s]){
				q++;
				mm[s]=q;
			}
			if (x<=n)f[x][y]=1;
			if (x<=n)xx[mm[s]]=x;
			if (x<=n)yy[mm[s]]=y;

		}else {
			if (!mm[s]){
				q++;
				mm[s]=q;
			}
			cin >> s;
			f[xx[mm[s]]][yy[mm[s]]]=0;
			cout << xx[mm[s]] << " " << yy[mm[s]] << endl;
			xx[mm[s]]=-1;
			yy[mm[s]]=-1;
		}
	}
	return 0;
}