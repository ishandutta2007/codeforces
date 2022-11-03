#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

char s[MAXN];
int n;

int cnt[100];
int umi;

inline char gao(int p){
	if (p < 10) return '0' + p;
	else if (p < 36) return p - 10 + 'a';
	else return p - 36 + 'A';
}

int check(int len){
	if (n % len != 0) return 0;
	if (len % 2 == 0){
		if (umi)
			return 0;
		printf("%d\n", n / len);
		for (int i = 0, pos = 0, pct = 0; i < n / len; i++){
			string t = "";
			for (int j = 0; j < len; j += 2){
				while(pct == cnt[pos]){
					pos++;
					pct = 0;
				}
				t.push_back(gao(pos));
				pct += 2;
			}
			for (int j = 0; j < t.length(); j++)
				putchar(t[j]);
			for (int j = len / 2 - 1; j >= 0; j--)
				putchar(t[j]);
			putchar(" \n"[i + 1 == n / len]);
		}
		return 1;
	}
	else{
		if (umi > n / len)
			return 0;
		printf("%d\n", n / len);
		string nico = "";
	//	cout << n << ' ' << len << endl;
		int kke = n / len;
		for (int i = 0; i < 62; i++){
			if (cnt[i] & 1){
				cnt[i]--;
				kke--;
				nico.push_back(gao(i));
			}
		}
		for (int i = 0; i < 62; i++){
			while (kke && cnt[i]){
				cnt[i]--;
				kke--;
				nico.push_back(gao(i));
			}
		}

	//	cout << "##" << nico << "##" << endl;

		for (int i = 0, pos = 0, pct = 0; i < n / len; i++){
			string t = "";
			for (int j = 0; j < len - 1; j += 2){
				while(pct == cnt[pos]){
					pos++;
					pct = 0;
				}
				t.push_back(gao(pos));
				pct += 2;
			}

	//		cout << i << " ###" << t <<"###" << endl;
	//		cout << t.length() << ' ' << len / 2 << endl;

			for (int j = 0; j < t.length(); j++)
				putchar(t[j]);
			putchar(nico[i]);
			for (int j = len / 2 - 1; j >= 0; j--)
				putchar(t[j]);
			putchar(" \n"[i + 1 == n / len]);
		}
		return 1;
	}
}

int main(){
	scanf("%d", &n);
	scanf("%s", s);
	umi = 0;
	for (int i = 0; i < n; i++)
		if (s[i] >= '0' && s[i] <= '9')
			cnt[s[i] - '0']++;
		else{
			if (s[i] >= 'a')
				cnt[s[i] - 'a' + 10]++;
			else
				cnt[s[i] - 'A' + 36]++;
		}
	for (int i = 0; i < 62; i++)
		if (cnt[i] & 1)
			umi++;
	for (int i = n; i >= 1; i--){
		if (check(i))
			break;
	}
	return 0;
}