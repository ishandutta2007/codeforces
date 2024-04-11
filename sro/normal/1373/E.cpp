/* by Natsu Kinmoe */
/* 2020/06/26 */
#include <bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int i=0;i<(n);i++)
#define pool(i,n) for(int i=(n)-1;i>=0;i--)
#define cont(i,n) for(int i=1;i<=(n);i++)
#define tnoc(i,n) for(int i=(n);i>=1;i--)
#define circ(i,a,b) for(int i=(a);i<=(b);i++)
#define cric(i,a,b) for(int i=(b);i>=(a);i--)
#define sub(i,a) for(int i=a;i;i=((i-1)&(a)))
#define subs(i,a) for(int i=a;i>=0;i=(!i?-1:((i-1)&(a))))
#define subt(i,a) for(int i=((a-1)&a);i;i=((i-1)&(a)))
#define subst(i,a) for(int i=((a-1)&a);i>=0;i=(!i?-1:((i-1)&(a))))
#define range(i,a,b,c) for(int i=(a);((c)>0?i<=(b):i>=(b));i+=(c))
#define foreach(it,v) for(__typeof((v).begin()) it=(v).begin(),_e_D_=(v).end();it!=_e_D_;it++)
#define parse(i,s) for(int i=0;s[i];i++)

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mak make_pair

#define y0 y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1 y1II11II11III11I1III11II111IIII1II1I1
#define ws WSrAkIoi2333wSraKIoIWSraKiOi
#define left left_jTjTJtJtIoiiOiioIAuaU66666jtIOIau
#define hash whYusEthiSnamE_caNyoUusEothERnaMesliKeHSH

#define Mask(a) (1ll<<(a))
#define Maskx(a,x) ((a)<<(x))
#define Full(a) ((1ll<<(a))-1)
#define Bit(a,x) (((a)>>(x))&1)
#define all(a) (a).begin(),(a).end()
#define SZ(a) ((int)((a).size()))

typedef long long ll;
typedef long double lf;

const int Inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3fll;
const lf inF=11451419198101145141919810.1145141919810;
const lf pi=acosl(-1);
/* Source code starts here */

int n,k;

void solve(){
	cin>>n>>k;
	string ans="\
::::::::'.   ``'';;;!!!!!;;;;;;!!;:`  .`''''''\
::::'`     ..':;;!!!!|||!!!!;!!!!!|;`   ``''''\
:`       .''::;|$@#####@&&%||!;!!!!!;'.  .``''\
       ..`':!&####@@&&&$$%||!!;;;;!!;:'.  ``''\
...    .`'!$##@@@&%|;;;!!;'';!;;!!;;;;:`   ```\
...   ..:%@@@@@@&%!!;''':::`.';;;;!;;;:'.   .`\
..   `'!&@@@@@@@&%!;;:'```::'.`:;;;:;;'`.  ...\
`..```;$@@@@@@@&&$|!!:'`.``'':::!!:;;;;:`.  .`\
  .':%@####@@@@&&&%|||!!!;;'`'::':;;;;;:`. ...\
``':%@#@@###@@&&&&$|:```''''`.`:|$|;::;;'.  ..\
:;:!$&&&@###@&$$$$$|;!%&%|;`..`;!!%!:::::`. ..\
':!%&$|%&@##@$%%$$$|;::'''`....   .:!;:'`.  ..\
::!&##&@###@&%|!|%%!'...     ....  .::''`....`\
:!$$||$##@@&$%|!!|%!'``..  .`''!|;'.:;'`.  .``\
:|$|;!%%%%%$$%|!!|%!:''```````'''``';!'`.....`\
!$@%;;!|%|!|%$%|!||!;::::'''```':;::!!:. ....`\
|&@@$!;!|%|!|%%|!!!;;::::'';%|;'''`:%|:.......\
%&@@@#&|;::;|%%%|!!;;:::'''``'':;;':%|:`......\
$@@@@@@##@&&&&$%%||!!;:::'''```..  .!%;`  .''`\
&@@@@@@@##@$%%$$$$%%|!!;;:::'''`````;%|!;:;!:;\
@@@@&@@@###&%|||%%%%%%%%%|||!!!;;;;|$$||%%%|::\
@@&&&&@@####&|!!!!!|||||||||%@###@&$$|!!|!;::'\
@&&&$&&&@#@@@$|;;::;;;;;;;;!&###@&$$$!:::;;;;;\
	";
	loop(i,10){
		int sum=0,jws=0;
		loop(j,k+1){
			sum+=(i+j)%10;
			if(i+j>=10)jws++;
		}
		string jo;
		loop(j,150){
			int rem=n-sum-(k+1-jws)*9*j-jws;
			if(rem<0)break;
			if(rem%(k+1)==0){
				string res=string(1,i+'0')+jo;
				int srm=rem/(k+1);
				if(srm){
					res+=char(min(8,srm)+'0');srm-=8;
					while(srm>0)res+=char(min(9,srm)+'0'),srm-=9;
				}
				reverse(all(res));
				if(res.size()<ans.size()||(res.size()==ans.size()&&res<ans))ans=res;
			}
			jo+="9";
		}
	}
	if(ans.size()>50)cout<<-1<<endl;
	else cout<<ans<<endl;
}

int main(){
	int T;cin>>T;
	while(T--)solve();return 0;
}