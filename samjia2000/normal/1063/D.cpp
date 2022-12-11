#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int main(){
	LL n,l,r,k;
	cin>>n>>l>>r>>k;
	LL lim=sqrt(k)+1;
	if (n<=lim){
		LL ans=-1;
		LL len;
		if (l<=r)len=r-l+1;
		else len=r+n-l+1;
		for(LL s=0;s<=n;s++){
			LL lef=max(0ll,s-(n-len)),rig=min(s,len);
			lef=lef+len,rig=rig+len;
			LL L=(k-rig)/(n+s),R=(k-lef)/(n+s);
			bool bz=0;
			for(LL all=L;all<=R;all++)
			if ((n+s)*all+lef<=k&&(n+s)*all+rig>=k)bz=1;
			if (bz)ans=s;
		}
		for(LL s=1;s<=n;s++){
			LL lef=max(1ll,s-(n-len))+len,rig=min(s,len)+len;
			LL L=(k+1-rig)/(n+s),R=(k+1-lef)/(n+s);
			bool bz=0;
			for(LL all=L;all<=R;all++)
			if ((n+s)*all+lef<=k+1&&(n+s)*all+rig>=k+1)bz=1;
			if (bz)ans=max(ans,s);
		}
		cout<<ans<<endl;
	}
	else{
		LL ans=-1;
		LL len;
		if (l<=r)len=r-l+1;
		else len=r+n-l+1;
		//all=0
		if (len<=k&&len*2>=k)ans=max(ans,k-len)+n-len;
		if (len<=k&&len*2>=k+1)ans=max(ans,k-len+1+n-len);
		for(LL all=1;all<=lim;all++){
			LL L=(k-n-len)/all-n,R=(k-len)/all-n;
			if (L<0)L=0;
			if (R>n)R=n;
			if (L<=R){
				//s<n-len&&s<len
				if (L<min(n-len,len)){
					// x in [0,s]
					LL l1=(k-len-n*all)/(all+1),r1=R;
					while((n+l1)*all+len+l1<k)l1++;
					if (l1<L)l1=L;
					if (r1>min(n-len,len)-1)r1=min(n-len,len)-1;
					if (l1<=r1)ans=max(ans,r1);
				}
				//s<n-len&&s>=len
				if (max(len,L)<=min(R,n-len-1)){
					// x in [0,len]
					LL l1=(k-len-len)/all-n,r1=R;
					while((n+l1)*all+len+len<k)l1++;
					if (l1<max(len,L))l1=max(len,L);
					if (r1>min(R,n-len-1))r1=min(R,n-len-1);
					if (l1<=r1)ans=max(ans,r1);
				}
				//s>=n-len&&s<len
				if(max(n-len,L)<=min(len-1,R)){
					// x in [s-(n-len),s]
					LL l1=(k-len-n*all)/(all+1),r1=(k-len+(n-len)-n*all)/(all+1);
					while((n+l1)*all+len+l1<k)l1++;
					if (l1<max(n-len,L))l1=max(n-len,L);
					if (r1>min(len-1,R))r1=min(len-1,R);
					if (l1<=r1)ans=max(ans,r1);
				}
				//s>=n-len&&s>=len
				if (max(max(n-len,len),L)<=R){
					// x in [s-(n-len),len]
					LL l1=(k-len-len)/all-n,r1=(k-len+(n-len)-n*all)/(all+1);
					while((n+l1)*all+len+len<k)l1++;
					if (l1<max(max(n-len,len),L))l1=max(max(n-len,len),L);
					if (r1>R)r1=R;
					if (l1<=r1)ans=max(ans,r1);
				}
			}
		}
		k++;
		for(LL all=1;all<=lim;all++){
			LL L=(k-n-len)/all-n,R=(k-len-1)/all-n;
			if (L<1)L=1;
			if (R>n)R=n;
			if (L<=R){
				//s<=n-len&&s<len
				if (L<min(n-len,len-1)){
					// x in [1,s]
					LL l1=(k-len-n*all)/(all+1),r1=R;
					while((n+l1)*all+len+l1<k)l1++;
					if (l1<L)l1=L;
					if (r1>min(n-len,len-1))r1=min(n-len,len-1);
					if (l1<=r1)ans=max(ans,r1);
				}
				//s<=n-len&&s>=len
				if (max(len,L)<=min(R,n-len)){
					// x in [1,len]
					LL l1=(k-len-len)/all-n,r1=R;
					while((n+l1)*all+len+len<k)l1++;
					if (l1<max(len,L))l1=max(len,L);
					if (r1>min(R,n-len))r1=min(R,n-len);
					if (l1<=r1)ans=max(ans,r1);
				}
				//s>n-len&&s<len
				if(max(n-len+1,L)<=min(len-1,R)){
					// x in [s-(n-len),s]
					LL l1=(k-len-n*all)/(all+1),r1=(k-len+(n-len)-n*all)/(all+1);
					while((n+l1)*all+len+l1<k)l1++;
					if (l1<max(n-len+1,L))l1=max(n-len+1,L);
					if (r1>min(len-1,R))r1=min(len-1,R);
					if (l1<=r1)ans=max(ans,r1);
				}
				//s>n-len&&s>=len
				if (max(max(n-len+1,len),L)<=R){
					// x in [s-(n-len),len]
					LL l1=(k-len-len)/all-n,r1=(k-len+(n-len)-n*all)/(all+1);
					while((n+l1)*all+len+len<k)l1++;
					if (l1<max(max(n-len+1,len),L))l1=max(max(n-len+1,len),L);
					if (r1>R)r1=R;
					if (l1<=r1)ans=max(ans,r1);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}