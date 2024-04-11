#include<bits/stdc++.h>
using namespace std;

int n, fg;
vector <int> ans;

bool inside(int x1, int y1, int x2, int y2){
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	scanf("%d", &fg);
	return fg > 0;
}

void determine(int x1, int x2, int y1, int y2){
///	puts("DET");
	int st, en, mid;

	st = x1, en = x2 + 1;
	while(st < en - 1){
		mid = (st + en) >> 1;
		if(inside(mid, y1, x2, y2)) st = mid;
		else en = mid;
	}
	x1 = st;
//	cout << "OK1" << endl;
	st = x1 - 1, en = x2;
	while(st < en - 1){
		mid = (st + en + 1) >> 1;
		if(inside(x1, y1, mid, y2)) en = mid;
		else st = mid;
	}
	x2 = en;
///	cout << "OK2" << endl;

	st = y1, en = y2 + 1;
	while(st < en - 1){
		mid = (st + en) >> 1;
		if(inside(x1, mid, x2, y2)) st = mid;
		else en = mid;
	}
	y1 = st;
///	cout << "OK3" << endl;

	st = y1 - 1, en = y2;
	while(st < en - 1){
		mid = (st + en + 1) >> 1;
		if(inside(x1, y1, x2, mid)) en = mid;
		else st = mid;
	}
	y2 = en;
///	cout << "OK4" << endl;

///	cout << "ANS  " << x1 << " " << x2 << " " << y1 << " " << y2 << endl;

	ans.push_back(x1);
	ans.push_back(y1);
	ans.push_back(x2);
	ans.push_back(y2);
}

bool sep1(int x1, int x2, int y1, int y2){
	int st, en, mid;
	st = x1 - 1, en = x2;
	while(st < en - 1){
		mid = (st + en + 1) >> 1;
		if(inside(x1, y1, mid, y2)) en = mid;
		else st = mid;
	}
	if(en == x2) return false;
	if(inside(en + 1, y1, x2, y2)){
		determine(x1, en, y1, y2);
		determine(en + 1, x2, y1, y2);
		printf("!");
		for(int i = 0; i < 8; i ++) printf(" %d", ans[i]); puts("");
		return true;
	}
	return false;
}

bool sep2(int x1, int x2, int y1, int y2){
	int st, en, mid;
	st = y1 - 1, en = y2;
	while(st < en - 1){
		mid = (st + en + 1) >> 1;
		if(inside(x1, y1, x2, mid)) en = mid;
		else st = mid;
	}
	if(en == y2) return false;
	if(inside(x1, en + 1, x2, y2)){
		determine(x1, x2, y1, en);
		determine(x1, x2, en + 1, y2);
		printf("!");
		for(int i = 0; i < 8; i ++) printf(" %d", ans[i]); puts("");
		fflush(stdout);
		return true;
	}
	return false;
}

int main(){
	scanf("%d", &n);
	if(sep1(1, n, 1, n)) return 0;
	if(sep2(1, n, 1, n)) return 0;
	assert(0);
}