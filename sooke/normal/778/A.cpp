#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std; 

string s , p;
int ans = 0 , a[200002];
bool u[200002];

int main(){
	cin >> s >> p;
	for(int i = 1 ; i <= s.size() ; i++)
		scanf("%d" , &a[i]);
	for(int l = 0 , r = s.size() , j , mid ; l <= r ; ){
		mid = l + r >> 1 ; j = 0;
		memset(u , false , sizeof(u));
		for(int i = 1 ; i <= mid ; i++)
			u[a[i]] = true;
		for(int i = 0 ; i < s.size() && j < p.size() ; i++)
			if(!u[i + 1] && s[i] == p[j])
				j++;
		if(j == p.size())
			l = mid + 1 , ans = mid;
		else
			r = mid - 1;
	}
	printf("%d\n" , ans);
	return 0;
}