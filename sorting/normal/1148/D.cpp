#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;

struct pir{
	int a, b, idx;

	pir(){}
	pir(int a, int b, int idx){
		this->a = a;
		this->b = b;
		this->idx = idx;
	}
};

bool cmp(pir lvalue, pir rvalue){
	return lvalue.b > rvalue.b;
}
bool cmp3(pir lvalue, pir rvalue){
	return lvalue.b < rvalue.b;
}

struct cmp2{
	bool operator()(pir lvalue, pir rvalue)const{
		return lvalue.b > rvalue.b;
	}
};

vector<pir> v1, v2;
vector<pir> sm;


vector<int> solve1(){
	set<pir, cmp2> left;

	sm.clear();
	left.clear();

	for(pir p: v1){
		sm.push_back(pir(p.a, p.b, p.idx));
		left.insert(p);
	}

	sort(sm.begin(), sm.end(), cmp);

	int i = 0;
	vector<int> ret;

	while(!left.empty()){
		pir big = *left.begin();

		ret.push_back(big.idx);
		if(left.count(big)){
			left.erase(big);
		}

		cout << big.a << " " << big.b << " " << big.idx << endl;

		while(i < (int)sm.size()){
			cout << sm[i].a << " " << sm[i].b << endl;
			if(sm[i].a > big.b){
				if(left.count(sm[i])){
					left.erase(sm[i]);
				}
				i++;
			}
			else{
				break;
			}
		}
	}

	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 1; i <= n; i++){
		int a, b;

		cin >> a >> b;

		if(a < b){
			v1.push_back(pir(a, b, i));
		}
		else{
			v2.push_back(pir(a, b, i));
		}
	}

	if(!v1.empty())
		sort(v1.begin(), v1.end(), cmp);
	if(!v2.empty())
		sort(v2.begin(), v2.end(), cmp3);

	if(v1.size() > v2.size()){
		cout << (int)v1.size() << "\n";
		for(pir p: v1){
			cout << p.idx << " ";
		}
		cout << "\n";
	}
	else{
		cout << (int)v2.size() << "\n";
		for(pir p: v2){
			cout << p.idx << " ";
		}
		cout << "\n";
	}

	return 0;
}
/*
3
3 5
4 6
1 2
*/