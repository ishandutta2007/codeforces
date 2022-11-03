#include <cstdio>
#include <map>

using namespace std;

map<int, int> lst;

int main(){
	int n;
	scanf("%d", &n);
	for (int u, t, i = 0; i < n; ++i){
		scanf("%d", &t);
		auto p = lst.insert(make_pair(t, 3)).first, q = p;
		if (p != lst.begin() && (--(q = p))->second & 2){
			q->second &= ~2;
			t = q->first;
		}
		else if ((++(q = p)) != lst.end() && q->second & 1){
			q->second &= ~1;
			t = q->first;
		}
		if (i)
			printf("%d%c", t, "\n "[i < n - 1]);
	}
	return 0;
}