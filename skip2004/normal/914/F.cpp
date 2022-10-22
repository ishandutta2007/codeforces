#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<bitset>
const int maxn = 100100;
std::bitset<maxn> s[26];
char ch[maxn],buf[maxn];
int n,m;
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> ch,n=strlen(ch);
	for(int i=0;i<n;++i)s[ch[i]-'a'].set(i);
	for(std::cin >> m;m--;){
		int opt,i,l,r;char c;
		std::cin >> opt;
		if(opt==1){
			std::cin >> i >> c,--i;
			s[ch[i]-'a'].reset(i),s[(ch[i]=c)-'a'].set(i);
		}else{
			std::cin >> l >> r >> buf;
			int len=strlen(buf);
			const int p = r - l + 1 - len + 1;
			if(p<0){
				std::cout << 0 << '\n';
				continue;
			}
			std::bitset<maxn> ans;ans.set();
			for(int i=0;i<len;++i)
				ans &= s[buf[i]-'a'] >> i + l - 1;
			std::cout << ans.count() - (ans>>p).count() << '\n';
		}
	}
}