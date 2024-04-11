#include <iostream>
#include <cstdio>
#define Maxn 1000001

using namespace std;

int len , v , stc[Maxn] , f[Maxn] , _max , cnt;
string s;

int main(){
	cin >> s;
	len = s.size();
	s = " " + s;
	for(int i = 1 ; i <= len ; i++)
		if(s[i] == '(')
			stc[++v] = i;
		else{
			if(v != 0){
				f[i] = i - stc[v] + 1 + f[stc[v] - 1];
				v--;
				if(_max < f[i])
					_max = f[i] , cnt = 1;
				else if(_max == f[i])
					cnt++;
			}
		}
	if(_max == 0)
		printf("0 1\n");
	else
		printf("%d %d\n" , _max , cnt);
	return 0;
}

// By Sooke.
// CF5C.