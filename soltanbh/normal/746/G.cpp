/*    |>>>                                                      |>>>
    |                     |>>>          |>>>                  |
    *                     |             |                     *
   / \                    *             *                    / \
  /___\                 _/ \           / \_                 /___\
  [   ]                |/   \_________/   \|                [   ]
  [ I ]                /     \       /     \                [ I ]
  [   ]_ _ _          /       \     /       \          _ _ _[   ]
  [   ] U U |        {#########}   {#########}        | U U [   ]
  [   ]====/          \=======/     \=======/          \====[   ]
  [   ]    |           |   I |_ _ _ _| I   |           |    [   ]
  [___]    |_ _ _ _ _ _|     | U U U |     |_ _ _ _ _ _|    [___]
  \===/  I | U U U U U |     |=======|     | U U U U U | I  \===/
   \=/     |===========| I   | + W + |   I |===========|     \=/
    |  I   |           |     |_______|     |           |   I  |
    |      |           |     |||||||||     |           |      |
    |      |           |   I ||vvvvv|| I   |           |      |
_-_-|______|-----------|_____||     ||_____|-----------|______|-_-_
   /________\         /______||     ||______\         /________\
  |__________|-------|________\_____/________|-------|__________|
*/
#include<iostream>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
ll a[200009],n,t,k,mx,mn,gh,ver,ca;
int main(){
	a[0]=1;mx=1;
	cin>>n>>t>>k;
	f(i,1,t+1){
		cin>>a[i];
		mn+=max(a[i-1]-a[i],(ll)0);
		mx+=a[i]-1;
	}
	mn+=a[t];
	if(k<mn || k>mx){cout<<-1;return 0;}
	cout<<n<<endl;
	ver=2;
	gh=1;
	f(i,1,t+1){
		ca=a[i];
		f(j,gh,gh+a[i-1]-1){
			if(mx>k && a[i]>1){
				mx--;
				cout<<j<<" "<<ver<<endl;
				a[i]--;
				ver++;
			}
		}
		f(j,0,a[i]){
			cout<<gh+a[i-1]-1<<" "<<ver<<endl;
			ver++;
		}
		a[i]=ca;
		gh=gh+a[i-1];
	}
}