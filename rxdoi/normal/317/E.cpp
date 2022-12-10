#include<cstdio>
#include<cctype>
#include<string>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Pb push_back
using namespace std;

int IN()
{
	int c,x,f;
	while (!isdigit(c=getchar())&&c!='-');(c=='-')?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}
void Print(string s)
{
	For(i,0,s.length()) putchar(s[i]=='U'?'L':s[i]=='D'?'R':s[i]=='L'?'D':'U');
}

const int O=400,N=O*O,oo=O/2;
struct Point
{
	int x,y;
	Point() {}
	Point(int _x,int _y) {x=_x,y=_y;}

	void I() {x=IN()+oo,y=IN()+oo;}
	Point operator + (const Point& B) const {return Point(x+B.x,y+B.y);}
	Point operator - (const Point& B) const {return Point(x-B.x,y-B.y);}

	bool InMap() {return x>=0&&x<O&&y>=0&&y<O;}
	bool operator == (const Point& B) const {return x==B.x&&y==B.y;}
	bool operator != (const Point& B) const {return !((*this)==B);}
	bool operator < (const Point& B) const {return x<B.x||x==B.x&&y<B.y;}
} Q[N],pre[O][O],S,T,Ul,Ur,Dl,Dr;
int Dis[O][O],M[O][O],m;
string Ans;
Point D[4]={(Point){1,0},(Point){-1,0},(Point){0,1},(Point){0,-1}};

void BFS(Point S)
{
	memset(Dis,-1,sizeof(Dis));Dis[S.x][S.y]=0;
	int f=1,w=0;Q[1]=S;
	while (f>w)
	{
		Point A=Q[++w];
		For(i,0,4)
		{
			Point B=A+D[i];
			if (!B.InMap()) continue;
			if (!M[B.x][B.y]&&Dis[B.x][B.y]==-1)
				Dis[B.x][B.y]=Dis[A.x][A.y]+1,Q[++f]=B,pre[B.x][B.y]=A;
		}
	}
}
bool To_Shadow()
{
	int f=0;
	for (Point A=T;A!=S;A=pre[A.x][A.y]) Q[++f]=A;
	reverse(Q+1,Q+f+1);
	for (int i=1;i<=f&&f+1<N;i++)
	{
		For(k,0,4) if ((Q[i]-S)==D[k]) Ans+="DURL"[k];
		Point P=T+(Q[i]-S);
		if (!P.InMap()||!M[P.x][P.y]) Q[++f]=T=P;
		S=Q[i];
	}
	return S==T;
}

void Go(int d)
{
	Ans+="DURL"[d],S=S+D[d];
	Point P=T+D[d];
	if (!P.InMap()||!M[P.x][P.y]) T=P;
}
void Work_1()
{
	if (T.y>=Ur.y) 
	{
		For(i,0,O) Go(2);
		while (T.x>=Ul.x) Go(1);
	}
	while (T.y>=Ul.y-O) Go(3);
	while (T.x!=Ul.x) Go(T.x<Ul.x?0:1);
	while (S.y!=T.y) Go(2);
	while (T.x>=Ul.x) Go(1);
	while (T.y!=Ul.y) Go(T.y<Ul.y?2:3);
	while (S!=T) Go(0); 
}
void Work_2()
{
	if (S.y>=Dr.y)
	{
		For(i,0,O) Go(2);
		while (T.x<=Dr.x) Go(0);
	}
	while (T.y>=Dl.y-oo) Go(3);
	while (T.x!=Dl.x) Go(T.x<Dl.x?0:1);
	while (S.y!=T.y) Go(2);
	while (T.x<=Dl.x) Go(0);
	while (T.y!=Dl.y) Go(T.y<Dl.y?2:3);
	while (S!=T) Go(1);
}
void Work_3()
{
	if (S.y<=Ul.y)
	{
		For(i,0,O) Go(3);
		while (T.x>=Ul.x) Go(1);
	}
	while (T.y<=Ur.y+oo) Go(2);
	while (T.x!=Ur.x) Go(T.x<Ur.x?0:1);
	while (S.y!=T.y) Go(3);
	while (T.x>=Ur.x) Go(1);
	while (T.y!=Ur.y) Go(T.y<Ur.y?2:3);
	while (S!=T) Go(0);
}
void Work_4()
{
	if (S.y<=Dl.y)
	{
		For(i,0,O) Go(3);
		while (T.x<=Dl.x) Go(0);
	}
	while (T.y<=Dr.y+oo) Go(2);
	while (T.x!=Dr.x) Go(T.x<Dr.x?0:1);
	while (S.y!=T.y) Go(3);
	while (T.x<=Dr.x) Go(0);
	while (T.y!=Dr.y) Go(T.y<Dr.y?2:3);
	while (S!=T) Go(1);
}

int main()
{
	S.I(),T.I();m=IN();
	if (!m) return puts("-1"),0;
	Ul=Ur=Point(1e9,0);
	Dl=Dr=Point(-1e9,0);
	For(i,0,m)
	{
		Point A;A.I();
		if (A.x<Ul.x||A.x==Ul.x&&A.y<Ul.y) Ul=A;
		if (A.x<Ur.x||A.x==Ur.x&&A.y>Ur.y) Ur=A;
		if (A.x>Dl.x||A.x==Dl.x&&A.y<Dl.y) Dl=A;
		if (A.x>Dr.x||A.x==Dr.x&&A.y>Dr.y) Dr=A;
		M[A.x][A.y]=1;
	}
	BFS(S);
	if (Dis[T.x][T.y]==-1) return puts("-1"),0;
	if (To_Shadow()) return Print(Ans),0;
	if (S.x<=T.x) S.y<=T.y?Work_1():Work_3();else S.y<=T.y?Work_2():Work_4();
	Print(Ans);
}