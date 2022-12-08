#include <bits/stdc++.h>

using namespace std;

struct FastIO{//scanf,printf,getchar,putchar,gets,puts,cin,cout
private:
	static const int BUFSIZE=1e5;
	char buf[BUFSIZE];int pos,len;//buffer()
	int wpos;char wbuf[BUFSIZE];//buffer
	char a[21];//
#define gc() (pos==len&&(len=(pos=0)+fread(buf,1,BUFSIZE,stdin),!len)?EOF:buf[pos++])
#define pc(c) (wpos==BUFSIZE?fwrite(wbuf,1,BUFSIZE,stdout),wpos=0,wbuf[wpos++]=c:wbuf[wpos++]=c)
public:
	FastIO():wpos(0),pos(0),len(0){}
	~FastIO(){if(wpos)fwrite(wbuf,1,wpos,stdout),wpos=0;}
	inline char getc(){return gc();}//char
	inline void putc(char c){pc(c);}//
	inline long long rd(){//long long
		long long x=0;char c=gc();bool f=0;
		for(;c<'0'||c>'9';c=gc())f|=c=='-';
		for(;c>='0'&&c<='9';c=gc())x=(x<<3)+(x<<1)+(c^48);
		return f?~x+1:x;
	}
	template<typename T>inline bool read(T &x){//while(io.read(n))work();ctrl Z
		x=0;char c=gc();bool f=0;
		for(;c<'0'||c>'9';c=gc()){if(c==EOF)return false;f|=c=='-';}
		for(;c>='0'&&c<='9';c=gc())x=(x<<3)+(x<<1)+(c^48);
		if(f)x=~x+1;return true;
	}
	template<typename T>inline void wt(T x){//
		if(x<0)pc('-'),x=-x;short h=0;
		for(a[++h]='0'+x%10,x/=10;x;x/=10)a[++h]='0'+x%10;
		while(h)pc(a[h--]);
	}
	template<typename T>inline void wtl(T x){wt(x);pc('\n');}//write line
	template<typename T>inline void wtb(T x){wt(x);pc(' ');}//write blank
	inline int gets(char *s){int l=0;char c=gc();for(;c<=' ';c=gc());for(;c>' ';c=gc())s[l++]=c;s[l]=0;return l;}
	inline void puts(const char *s){const char *p=s;while(*p)pc(*p++);}// ()
	template<typename T>inline FastIO & operator >> (T &a){return read(a),*this;}//io>>a>>b;
	template<typename T>inline FastIO & operator << (T a){return wtb(a),*this;}//io<<a<<b;
}io;//ctrl Z

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t = io.rd();
	while (t--) {
		int n = io.rd(), m = io.rd();
		std::vector<int> b(m + 1), c(m + 1), dp(m + 1);
		int mn = 1e9, mx = 0;
		for (int i = 0; i < n; ++i) {
			int x = io.rd();
			b[x] = 1;
			c[x] = 1;
			mn = std::min(mn, x);
			mx = std::max(mx, x);
		}
		for (int i = 1; i <= mx; ++i) {
			dp[i] = i;
		}
		int p = mx, ans = 1e9;
		for (int i = mx; i >= 1; --i) {
			for (i64 j = (i64) i * i; j <= mx; j += i) {
				if (b[j]) --c[dp[j]];
				dp[j] = std::min(dp[j], dp[j / i]);
				if (b[j]) ++c[dp[j]];
			}
			while (!c[p]) --p;
			if (i <= mn) ans = std::min(ans, p - i);
		}
		io.wtl(ans);
	}
	return 0;
}