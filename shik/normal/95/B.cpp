// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	string s,t;
	cin>>s;
	int n=s.size();
	if ( n%2==0 ) {
		if ( string(n/2,'7')+string(n/2,'4')<s ) cout<<string(n/2+1,'4')<<string(n/2+1,'7')<<endl;
		else {
			int flg=0,r4=n/2,r7=n/2;
			for ( int i=0; i<n; i++ ) {
				int tmt=0,p;
				if ( r4>0 ) {
					if ( flg || s[i]<'4' ) tmt=1;
					else if ( s[i]=='4' ) {
						p=i+1;
						for ( p=i+1; p<=n; p++ ) {
							if ( p==n ) { tmt=1; break; }
							char c=(p<=i+r7?'7':'4');
							if ( c>s[p] ) tmt=1;
							if ( c!=s[p] ) break;
						}
					}
				}
				if ( tmt ) t+="4",r4--;
				else t+="7",r7--;
				if ( t[i]>s[i] ) flg=1;
			}
			cout<<t<<endl;
		}
	} else {
		n++;
		cout<<string(n/2,'4')<<string(n/2,'7')<<endl;
	}
	return 0;
}