#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100000];
ll ask(int l,int r)
{
	ll x=0;
	//	for (int i=l;i<=r;i++) for (int j=i+1;j<=r;j++) x+=a[i]>a[j];
	cout<<"? "<<l<<' '<<r<<endl;
	//	cout<<x<<endl;
	//	return x;
	cin>>x;
	if (x==-1) while (1);
	return x;
}
void answer(int i,int j,int k)
{
	cout<<"! "<<i<<' '<<j<<' '<<k<<endl;
}
ll cal(ll x)//n*(n-1)/2=x
{
	x<<=1;
	ll ans=round(sqrt(1+4*x));
	while ((ans-1)*(ans-1)>=1+4*x) --ans;
	while ((ans+1)*(ans+1)<=1+4*x) ++ans;
	if (ans*ans!=1+4*x||(1^ans&1)) return -1;
	return 1+ans>>1;
}
//n^2-n-x=0;1+sqrt(1+4x)
int main()
{
	srand(time(0));
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	t=100;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		//n=1e3;
			//int i,j,k;
			//for (i=1;i<=n;i++) a[i]=i;
			//i=rand()%(n-3)+1;j=rand()%(n-1)+1;while (i>=j-1) j=rand()%(n-1)+1;
			//k=rand()%n+1;while (k<=j) k=rand()%n+1;
			////cin>>i>>j>>k;
			//reverse(a+i,a+j);
			//reverse(a+j,a+k+1);
			//cout<<i<<' '<<j<<' '<<k<<endl;
			//for (int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
		int l=1,r=n;
		ll tot=ask(1,n);
		while (l<r)
		{
			int mid=l+r>>1;
			ll x=ask(1,mid);
			ll Y=x;
			x=cal(x);//cout<<x<<endl;
			if (x==1) l=mid+1;
			else if (Y==tot) r=mid;
			else if (x==-1)
			{
				ll now=ask(mid,n),pos=mid;
				ll len=cal(now);assert(len>=0);
				pos=pos+len-1;//cout<<"pos = "<<pos<<endl;
				r=mid;
				while (l<r)
				{
					mid=l+r>>1;
					ll x=ask(mid,n);
					if (x*2==(pos-mid+1)*(pos-mid)) r=mid; else l=mid+1;
				}
			}
			else
			{
				ll pos=mid-x+1;
				ll y=ask(1,pos+1);
				ll z=ask(1,pos);
				if (y==1&&z==0)
				{
					l=mid+1;
					while (l<r)
					{
						mid=l+r>>1;
						x=ask(pos,mid);
						if ((mid-pos)*(mid-pos+1)==2*x) l=mid+1; else r=mid;
					}
				}
				else
				{
					ll now=ask(mid,n),pos=mid;
					ll len=cal(now);assert(len>=0);
					pos=pos+len-1;
					r=mid;
					while (l<r)
					{
						mid=l+r>>1;
						ll x=ask(mid,n);
						if (x*2==(pos-mid+1)*(pos-mid)) r=mid; else l=mid+1;
					}
				}
			}
		}
		ll ans=cal(ask(1,l-1));
		ll anss=cal(ask(l,n));
		answer(l-ans,l,l+anss-1);
		//assert(l-ans==i&&l==j&&l+anss-1==k);
	}
}

/*
2 1 5 4 3
*/