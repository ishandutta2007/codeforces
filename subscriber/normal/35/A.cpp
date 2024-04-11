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

int n,f[4],x,y;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n;
	f[1]=0;
	f[2]=0;
	f[3]=0;
	f[n]=1;
	for (int i=0;i<3;i++){
		cin >> x >> y;
		swap(f[x],f[y]);	
	}
	for (int i=1;i<=3;i++)if (f[i])cout << i << endl;
	return 0;
}