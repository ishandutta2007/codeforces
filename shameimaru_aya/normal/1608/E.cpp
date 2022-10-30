#include <bits/stdc++.h> 
using namespace std;
int n , ans , bb , t[10] , id[10] , l , tot , lim;
struct item 
{
	int x , y , c;
} nx[110000] , ny[110000];
bool cmpx( item a , item b )
{
	return a.x < b.x;
}
bool cmpy( item a , item b )
{
	return a.y < b.y;
}
int scan( int c , int k )
{
	tot = 0;
	for( ; l <= n ; l++ )
	{
		if(nx[l].y <= lim) continue;
		if(nx[l].c == c)
		{
			tot++;
			if(tot == k) break;
		}
	}
	int f = 0;
	for(int i = l ; i <= n ; i++ ) 
	{
		if(nx[i].x != nx[l].x) 
		{
			l = i; f = 1;
			break;
		}
	}
	if(f == 0) l = n + 1;
	if(tot != k) return 0;
	return 1;
}
int check1( int k )
{
	l = 1;
	if(!scan(t[1] , k)) return 0;
	if(!scan(t[2] , k)) return 0;
	if(!scan(t[3] , k)) return 0;
	return 1;
}
void binary1( int l , int r )
{
	if(l > r) return ;
	int mid = l + r >> 1;
	if(check1(mid)) bb = mid , binary1(mid + 1 , r);
	else binary1(l , mid - 1);
}

int check2( int k )
{
	l = 1 , tot = 0;
	for(int i = 1 ; i <= n ; i++ )
	{
		if(ny[i].c == t[1])
		{
			tot++; lim = ny[i].y;
			if(tot == k) break;
		}
	}
	if(!scan(t[2] , k)) return 0;
	if(!scan(t[3] , k)) return 0;
	return 1;
}
void binary2( int l , int r )
{
	if(l > r) return ;
	int mid = l + r >> 1;
	if(check2(mid)) bb = mid , binary2(mid + 1 , r);
	else binary2(l , mid - 1);
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &n); lim = -2e9;
	for(int i = 1 ; i <= n ; i++ ) scanf("%d%d%d" , &nx[i].x , &nx[i].y , &nx[i].c);
	sort(nx + 1 , nx + n + 1 , cmpx); 
	t[1] = 1; t[2] = 2; t[3] = 3; 
	for(int i = 1 ; i <= 6 ; i++ )
	{
		binary1(1 , n / 3); ans = max(ans , bb);
		if(i != 6) next_permutation(t + 1 , t + 4);
	}
	
	t[1] = 1; t[2] = 2; t[3] = 3; 
	for(int i = 1 ; i <= n ; i++ ) swap(nx[i].x , nx[i].y);
	sort(nx + 1 , nx + n + 1 , cmpx); 
	for(int i = 1 ; i <= 6 ; i++ )
	{
		binary1(1 , n / 3); ans = max(ans , bb);
		if(i != 6) next_permutation(t + 1 , t + 4);
	}
	
	t[1] = 1; t[2] = 2; t[3] = 3; 
	for(int i = 1 ; i <= n ; i++ ) swap(nx[i].x , nx[i].y);
	memcpy(ny , nx , sizeof(ny));
	sort(nx + 1 , nx + n + 1 , cmpx); sort(ny + 1 , ny + n + 1 , cmpy); 
	for(int i = 1 ; i <= 6 ; i++ )
	{
		binary2(1 , n / 3); ans = max(ans , bb);
		if(i != 6) next_permutation(t + 1 , t + 4);
	}
	
	t[1] = 1; t[2] = 2; t[3] = 3; 
	for(int i = 1 ; i <= n ; i++ ) nx[i].y = -nx[i].y;
	memcpy(ny , nx , sizeof(ny));
	sort(nx + 1 , nx + n + 1 , cmpx); sort(ny + 1 , ny + n + 1 , cmpy); 
	for(int i = 1 ; i <= 6 ; i++ )
	{
		binary2(1 , n / 3); ans = max(ans , bb);
		if(i != 6) next_permutation(t + 1 , t + 4);
	}
	
	t[1] = 1; t[2] = 2; t[3] = 3; 
	for(int i = 1 ; i <= n ; i++ ) swap(nx[i].x , nx[i].y);
	memcpy(ny , nx , sizeof(ny));
	sort(nx + 1 , nx + n + 1 , cmpx); sort(ny + 1 , ny + n + 1 , cmpy); 
	for(int i = 1 ; i <= 6 ; i++ )
	{
		binary2(1 , n / 3); ans = max(ans , bb);
		if(i != 6) next_permutation(t + 1 , t + 4);
	}
	
	t[1] = 1; t[2] = 2; t[3] = 3; 
	for(int i = 1 ; i <= n ; i++ ) nx[i].y = -nx[i].y;
	memcpy(ny , nx , sizeof(ny));
	sort(nx + 1 , nx + n + 1 , cmpx); sort(ny + 1 , ny + n + 1 , cmpy); 
	for(int i = 1 ; i <= 6 ; i++ )
	{
		binary2(1 , n / 3); ans = max(ans , bb);
		if(i != 6) next_permutation(t + 1 , t + 4);
	}
	
	cout << ans * 3;
    return 0;
} 
/*

*/