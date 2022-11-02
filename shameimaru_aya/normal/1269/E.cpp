#include<bits/stdc++.h>
using namespace std;
long long ans , n , a[210000] , x , sum1 , sum2 , las;
int rd[450000] , siz[450000] , son[450000][2] , v[450000] , root , num[450000] , cnt;
priority_queue< int > q1;
priority_queue< int , vector< int > , greater< int > > q2;
inline void update( int x )
{
	if(!q2.size() || x > q2.top()) q2.push(x) , sum2 += x;
	else q1.push(x) , sum1 += x;
	if(q1.size() > q2.size() + 1)
	{
		sum1 -= q1.top() , sum2 += q1.top();
		q2.push(q1.top());
		q1.pop();
	}
	if(q2.size() > q1.size() + 1)
	{
		sum2 -= q2.top() , sum1 += q2.top();
		q1.push(q2.top());
		q2.pop();
	}
	return ;
}
inline int ask()
{
	if(q1.size() > q2.size()) return q1.top();
	return q2.top();
}
int judge( int id )
{
	int ans = 1;
	if(son[id][0])
	ans++;
	if(son[id][1])
	ans += 2;
	return ans;
}
void push_up( int id )
{
	siz[id] = siz[son[id][0]] + siz[son[id][1]] + num[id];
	return ;
}
void rotate( int &p , int d )	//01 
{
	int r = son[p][d ^ 1];
	son[p][d ^ 1] = son[r][d];
	son[r][d] = p;
	push_up(p);
	push_up(r);
	p = r;
	return ;
}
void ins( int &p , int d )
{
	if(!p)
	{
		p = ++cnt;
		v[p] = d;
		num[p] = siz[p] = 1;
		rd[p] = rand();
		return ;
	}
	if(v[p] == d)
	{
		num[p]++;
		siz[p]++;
		return ;
	}
	int t = 0;
	if(v[p] < d)
	t = 1;
	ins(son[p][t] , d);
	if(rd[p] < rd[son[p][t]]) rotate(p , t ^ 1);
	push_up(p);
	return ;
}
int rk( int p , int x )
{
	if(!p) return 0;
	if(v[p] == x) return siz[son[p][0]] + 1;
	if(v[p] < x) return siz[son[p][0]] + rk(son[p][1] , x) + num[p];
	if(v[p] > x) return rk(son[p][0] , x);
}
int find( int p , int x )
{
	if(!p) return 0;
	if(siz[son[p][0]] >= x) return find(son[p][0] , x);
	if(siz[son[p][0]] + num[p] >= x) return v[p];
	return find(son[p][1] , x - (siz[son[p][0]] + num[p]));
}
int main()
{
	srand((unsigned)time(NULL));
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ )
	{
		scanf("%d" , &x);
		a[x] = i;
	}
	for(int i = 1 ; i <= n ; i++ )
	{
		update(a[i]);
		int x = ask();
//		cerr << q1.size() << " " << q2.size() << " " << sum1 << " " << sum2 << " " << x << "\n";
		if(q2.size() >= q1.size())
		{
			ans = sum2 - (1ll * q2.size() * x) - 1ll * (q2.size() - 1) * q2.size() / 2;
			ans += (1ll * q1.size() * x) - sum1 - 1ll * (q1.size() + 1) * q1.size() / 2;
		}
		else
		{
			ans = sum2 - (1ll * q2.size() * x) - 1ll * (q2.size() + 1) * q2.size() / 2;
			ans += (1ll * q1.size() * x) - sum1 - 1ll * (q1.size() - 1) * q1.size() / 2;
		}
//		cerr << ans << endl;
		ins(root , a[i]);
		long long rr = rk(root , a[i]);
//		cerr << rr << ' ';
		las += i - rr;
		ans += las;
		printf("%lld " , ans);
	}
	return 0;
}