#include <bits/stdc++.h>



using namespace std;



#define MM 100001

int n, cnt;

char str[MM], a[MM];

string s;

int main()

{

//	freopen ("in.txt", "r", stdin);

	scanf ("%d", &n);

	for (int i=0; i<n; i++){

		s+="<3";

		scanf ("%s", a); s+=a;

	}

	s+="<3";

	scanf ("%s", str);

	int len=strlen(str);

	for (int i=0; i<len; i++){

		if(str[i]==s[cnt])cnt++;

	}

	if(cnt!=s.length()) puts("no");

	else puts("yes");

	return 0;

}