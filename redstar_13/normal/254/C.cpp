#include <bits/stdc++.h>



using namespace std;



#define MM 110000



char a[MM], b[MM], str[MM];

int freq[100][2], f[100], cnt;

int main()

{

	int j;

	freopen ("input.txt", "r", stdin);

	freopen ("output.txt", "w", stdout);

	scanf ("%s%s", a, b);  int len=strlen(a);

	for (int i=0; i<len; i++){

		freq[a[i]-'A'][0]++; freq[b[i]-'A'][1]++;

	}

	for (int i=0; i<len; i++){

		int r=a[i]-'A';

		int x=freq[r][0], y=freq[r][1];

		if(x>y){

			if(f[r]<y){

				for(j=0; j<r; j++){

					if(freq[j][0]<freq[j][1]){ str[i]=j+'A'; freq[j][0]++; freq[r][0]--; cnt++; break;}

				}

				if(j>=r) f[r]++, str[i]=a[i];

			}

			else{

				for(j=0; j<26; j++){

					if(freq[j][0]<freq[j][1]){str[i]=j+'A'; freq[j][0]++; freq[r][0]--; cnt++; break;}

				}

			}

		}

		else str[i]=a[i];

	}

	cout<<cnt<<endl;

	for (int i=0; i<len; i++) cout<<str[i]; cout<<endl;

	return 0;

}