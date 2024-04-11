#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

string a,s[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int x;

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> a >> x;
	for (int i=0;i<12;i++)if (a==s[i]){
		cout << s[(i+x)%12] << endl;
	}
	return 0;
}