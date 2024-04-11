#include <bits/stdc++.h>

#define endl '\n'
#define left jhghajkhja
#define right oauighgajk
#define prev aioghajga
#define next ioyhjhfajasj
#define y0 iuadoghasdgj
#define y1 taklahgjkla
#define remainder pogjuakllhga
#define pow pajklgaklha
#define pow10 iopuioadjlgkah
#define div aljghajkghak
#define distance gkuftgjasgfjh
#define uppercase ifyhasjkhakjfas

//#define floor hjakjhaja
//#define time ashjlahjka
//#define double_t double
//#define tm kahjflahaajk

using namespace std;

const int N = 1<<18;

int n;
string a[N];
set < string > s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("test.txt","r",stdin);
    //freopen(IN.c_str(),"r",stdin);
    //freopen(OUT.c_str(),"w",stdout);
    //fread(buff,1,sizeof(buff),stdin);
    int i;
    
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
	reverse(a+1,a+1+n);
	for(i=1;i<=n;i++) {
		if(s.find(a[i])==s.end()) {
			s.insert(a[i]);
			cout<<a[i]<<endl;
		}
	}
    
    //fprintf(stderr, "Time: %d ms\n", (int)(clock()*1000.0/CLOCKS_PER_SEC));

    return 0;
}