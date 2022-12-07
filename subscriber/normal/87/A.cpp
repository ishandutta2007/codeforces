#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	int a,b;
	cin >> a >> b;
	if (abs(a-b)==__gcd(a,b))puts("Equal");else if (a<b)puts("Dasha");else puts("Masha");
	return 0;
}