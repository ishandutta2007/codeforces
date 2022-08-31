#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long LL;
#define MP make_pair
#define INF 100000000
typedef pair<int,int> PI;

set<PI> S[105];
int N,K,mid;
set<PI>::iterator it;

int i,j,k,m;
int cx,cyl,cyr,cd,cy1,cy2;
int bx,byl,byr,bd,by1,by2;


void update()
{
	if(cd>bd) return;
	
	if(cd<bd)
	{
		bd=cd; bx=cx; byl=cyl; byr=cyr; by1=cy1; by2=cy2;
	}
	else if(cd==cd)
	{
		if(cx<bx || (cx==bx&&cyl<byl) )
		{
			bd=cd; bx=cx; byl=cyl; byr=cyr; by1=cy1; by2=cy2;
		}
	}
}

int main()
{
	
	cin>>N>>K;
	
	mid = (K+1)/2;
	
	for(i=1;i<=K;i++) S[i].insert(MP(1,K));
	
	while(N--)
	{
		cin>>m;
		bd=INF;
	
		for(i=1;i<=K;i++)
		{
			cx=i;
			for(it=S[i].begin();it!=S[i].end();it++)
			{
				cy1=(*it).first, cy2=(*it).second;
				if(cy2-cy1+1<m) continue;
				
				if(cy1>mid)
				{
					cd = m*abs(i-mid) + m*(cy1-mid) + m*(m-1)/2;
					cyl=cy1; cyr=cy1+m-1;
					update();
				}
				
				else if(cy2<mid)
				{
					cd = m*abs(i-mid) + m*(mid-cy2) + m*(m-1)/2;
					cyr=cy2; cyl=cy2-m+1;
					update();	
				}
				
				else if(cy1<=mid && cy2>=mid)
				{
					cyl = mid - (m/2);
					cyr = mid + (m-1)/2;
					
					if(cyr>cy2)
					{
						cyr = cy2;
						cyl = cy2-m+1;
					}
					
					else if(cyl<cy1)
					{
						cyl = cy1;
						cyr = cy1+m-1;
					}
					
					cd = m*abs(i-mid);
					k = mid-cyl; cd+=k*(k+1)/2;
					k = cyr-mid; cd+=k*(k+1)/2;
					update();
				}
			}
		}	
			
		if(bd==INF) cout<<-1<<endl;
		else cout<<bx<<" "<<byl<<" "<<byr<<endl;
		
		if(bd!=INF)
		{
			//cout<<"Erasing in "<<bx<<" --> "<<by1<<" <--> "<<by2<<endl;
			S[bx].erase(MP(by1,by2));
			S[bx].insert(MP(by1,byl-1));
			S[bx].insert(MP(byr+1,by2));
			//cout<<"Adding in "<<bx<<" --> "<<by1<<" <--> "<<byl-1<<" and "<<byr+1<<" <--> "<<by2<<endl<<endl<<endl;
		}
	}
	
	return 0;
}