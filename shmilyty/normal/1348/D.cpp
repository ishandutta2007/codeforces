#include<bits/stdc++.h>
#define int long long
using namespace std;

int read() {
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9') {
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}

int n,p[100001];

signed main() {
	int t=read();
    while (t--) {
        n=read();
        int d=0,tot=0,t=1;
        for (;tot<n;d++,t<<=1) {
            tot+=t;
        }
        d--;
        n=n-1-d;
        int hold=1,k;
        for (int i=d;i>=1;--i) {
            k=min(n/i,hold);
            p[d-i+1]=k;
            n-=k*i;
            hold+=k;
        }
        
        if (n!=0) {
            cout<<-1<<endl;
        } 
		else {
            cout<<d<<endl;
            for(int i=1;i<=d;++i)
                cout<<p[i]<< " ";
            cout<<endl;
        }
    }
	return 0;
}