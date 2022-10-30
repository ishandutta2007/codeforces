#include <bits/stdc++.h> 
using namespace std;
int n , op , x , y;
struct item
{
	int x , y;
	bool operator < ( const item &a ) const
	{
		if(x != a.x) return x < a.x;
		return y < a.y;
	}
	bool operator == ( const item &a ) const
	{
		return x == a.x && y == a.y;
	}
	item operator - ( const item &a ) const
	{
		return (item){x - a.x , y - a.y};
	}
	long long operator * ( const item &a ) const
	{
		return 1ll * x * a.y - 1ll * a.x * y;
	}
};
set< item > A , B;
int insert( item p , set< item > &A , int f )
{
	if(A.size() < 2) 
	{
		if(f) A.insert(p);
		return 1;
	}
	set< item >::iterator it = A.lower_bound(p) , it1 , it2;
	if(it != A.end() && (*it) == p) return 0;
	A.insert(p); it = A.lower_bound(p);
	if(f)
	{
		if(it != A.begin())
		{
			it1 = it; it1--; 
			if(it1 != A.begin()) 
			{
				it2 = it1; it2--;
				while(((*it1) - (*it2)) * ((*it) - (*it1)) >= 0) 
				{
					A.erase(it1); 
					it = A.lower_bound(p); 
					if(it == A.begin()) break;
					it1 = it; it1--;
					if(it1 == A.begin()) break;
					it2 = it1; it2--;
				}
			}
		} 
		it = A.lower_bound(p); it1 = it; it1++; 
		if(it1 != A.end())
		{
			it2 = it1; it2++;
			if(it2 != A.end()) 
			{
				while(((*it1) - (*it)) * ((*it2) - (*it1)) >= 0) 
				{
					A.erase(it1); 
					it = A.lower_bound(p); 
					it1 = it; it1++;
					if(it1 == A.end()) break;
					it2 = it1; it2++;
					if(it2 == A.end()) break;
				}
			}
		} 
	}
	int qwq = 1;
	it = A.lower_bound(p); it2 = it; it2++;
	if(it2 != A.end() && it != A.begin())
	{ 
		it1 = it; it1--;
//		cerr << ((*it) - (*it1)).x << ' ' <<((*it) - (*it1)).y
//		 << ' ' << ((*it2) - (*it)).x << ' ' << ((*it2) - (*it)).y << ' '
//		 << ((*it) - (*it1)) * ((*it2) - (*it)) << endl;
		if(((*it) - (*it1)) * ((*it2) - (*it)) >= 0) qwq = 0;
		if(((*it) - (*it1)) * ((*it2) - (*it)) >= 0) A.erase(p);
	} 
	if(!f) A.erase(p);
	return qwq;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &n);
	while(n--)
	{
		scanf("%d%d%d" , &op , &x , &y);
		int qwq = insert((item){x , y} , A , op % 2);
		qwq |= insert((item){x , -y} , B , op % 2);
		if(op == 2) 
		{
			if(!qwq) printf("YES\n");
			else printf("NO\n");
		}
//		for(item a : A) cerr << a.x << ' ' << a.y << endl;
//		for(item a : B) cerr << a.x << ' ' << a.y << endl; cerr << endl;
	}
    return 0; 
} 
/*

*/