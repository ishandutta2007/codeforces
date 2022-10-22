#include<bits/stdc++.h>
typedef std::vector<int> vec;
int n,k;
inline int cal(int x){
	for(;x%k==0;x/=k);
	return x;
}
int main(){
	std::cin >> n >> k;
	vec a;
	struct T{int a,b;};
	for(int i = 0,x;i<n;++i) std::cin >> x,a.push_back(x);
	std::mt19937 rd(time(0));
	do{
		vec b = a;
		std::vector<T> vec;
		while(b.size() > 1){
			std::shuffle(b.begin(),b.end(),rd);
			int x = b[b.size() - 1];
			int y = b[b.size() - 2];
			b.pop_back(); b.pop_back();
			vec.push_back({x,y});
			b.push_back(cal(x + y));
		}
		if(b[0] == 1){
			std::cout << "YES" << '\n';
			for(auto i : vec){
				std::cout << i.a << ' ' << i.b << '\n';
			}
			return 0;
		}
	}while(double(clock()) / CLOCKS_PER_SEC < 1.6);
	std::cout << "NO" << '\n';
}