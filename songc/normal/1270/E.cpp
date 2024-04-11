#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N;
struct Point{
	int x, y, id;
};
vector<Point> P, OO, EE, OE, EO;

int main(){
	scanf("%d", &N);
	if (N == 2){
		printf("1\n1\n");
		return 0;
	}
	for (int i=1; i<=N; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		P.push_back((Point){x, y, i});
	}
	while (1){
		for (Point p : P){
			if (p.x&1){
				if (p.y&1) OO.push_back(p);
				else OE.push_back(p);
			}
			else{
				if (p.y&1) EO.push_back(p);
				else EE.push_back(p);
			}
		}
		if (OO.size()+EE.size() && OO.size()+EE.size() != N){
			printf("%d\n", OO.size()+EE.size());
			for (Point p : OO) printf("%d ", p.id);
			for (Point p : EE) printf("%d ", p.id);
			printf("\n");
			return 0;
		}
		else if (OO.size() && OO.size() != N){
			printf("%d\n", OO.size());
			for (Point p : OO) printf("%d ", p.id);
			printf("\n");
			return 0;
		}
		else if (OE.size() && OE.size() != N){
			printf("%d\n", OE.size());
			for (Point p : OE) printf("%d ", p.id);
			printf("\n");
			return 0;
		}
		OO.clear();
		OE.clear();
		EO.clear();
		EE.clear();
		for (Point &p : P){
			if (p.x&1) p.x++;
			if (p.y&1) p.y++;
			p.x /= 2;
			p.y /= 2;
		}
	}
	return 0;
}