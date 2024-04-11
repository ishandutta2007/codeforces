#include <cstdio>
#include <cmath>
#define Max(x , y) ((x) > (y) ? (x) : (y))
#define Min(x , y) ((x) < (y) ? (x) : (y))
#define Eps 0.00000001
#define Maxn 205

struct Point{
    double x , y;
};

inline double Dis(Point a , Point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
inline double CrossMul(Point a , Point b , Point c){
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
inline double _CrossMul(Point a , Point b , Point c){
    return (b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y);
}

inline bool IsCross(Point a , Point b , Point c , Point d){
    if(CrossMul(a , b , c) * CrossMul(a , b , d) >= Eps)
        return false;
    if(CrossMul(c , d , a) * CrossMul(c , d , b) >= Eps)
        return false;
    if(Min(a.x , b.x) <= Max(c.x , d.x) && Min(c.x , d.x) <= Max(a.x , b.x) && Min(a.y , b.y) <= Max(c.y , d.y) && Min(c.y , d.y) <= Max(a.y , b.y))
        return true;
    return false;
}

Point P[Maxn];
double l = 200 , r = -200 , d = 200 , u = -200;

inline bool Check(){
	for(int i = 5 ; i <= 8 ; i++)
		if(!(l <= P[i].x && P[i].x <= r && d <= P[i].y && P[i].y <= u))
			return false;
	return true;
}

inline bool CheckA(){
	for(int i = 5 ; i <= 8 ; i++)
		for(int j = 1 ; j <= 4 ; j++)
			if(CrossMul(P[i] , P[i % 4 + 5] , P[j]) < -Eps)
				return false;
	return true;
}
inline bool CheckB(){
	for(int i = 5 ; i <= 8 ; i++)
		for(int j = 1 ; j <= 4 ; j++)
			if(CrossMul(P[i] , P[i % 4 + 5] , P[j]) > Eps)
				return false;
	return true;
}

int main(){
	for(int i = 1 ; i <= 8 ; i++)
		scanf("%lf%lf" , &P[i].x , &P[i].y);
	for(int i = 1 ; i <= 4 ; i++)
		for(int j = 5 ; j <= 8 ; j++)
			if(IsCross(P[i] , P[i % 4 + 1] , P[j] , P[j % 4 + 5])){
				printf("YES\n");
				return 0;
			}
	for(int i = 1 ; i <= 4 ; i++){
		l = Min(l , P[i].x);
		r = Max(r , P[i].x);
		d = Min(d , P[i].y);
		u = Max(u , P[i].y);
	}
	if(Check()){
		printf("YES\n");
		return 0;
	}
	if(_CrossMul(P[5] , P[6] , P[7]) >= Eps){
		if(CheckA()){
			printf("YES\n");
			return 0;
		}
	}else{
		if(CheckB()){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
    return 0;
}

// By Sooke.
// CF993A Two Squares.