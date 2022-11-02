#include<bits/stdc++.h>



using namespace std;



char s[200010], m[200010];

int n, i, o, vst[200010], cnt=0, flag;



int main(){

	

	scanf("%s", s);

	n=strlen(s);

	for(i=1; i<n; i++){

		if(s[i]==s[i-1]){

			cnt++;

			if(cnt>1) vst[i]=1;

		}

		else cnt=0;

	}

	

	for(i=0; i<n; i++)	if(vst[i]==0) m[o++]=s[i];

	

	n=o;

	for(i=0; i<n; i++) s[i]=m[i];

	

	memset(vst, 0, sizeof(vst));

	

	for(i=1; i<n; i++){

		if(s[i]!=s[i-1]){

			flag=0;

			continue;

		}

		if(flag) { vst[i]=1, flag=0; continue;}

		flag=1;

		i++;

	}

	

	for(i=0; i<n; i++) if(vst[i]==0) putchar(s[i]);

	return 0;

}