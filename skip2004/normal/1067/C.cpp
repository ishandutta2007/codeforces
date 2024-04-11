#include<bits/stdc++.h>
int n;
void write(int x, int y) {
	printf("%d %d\n", x, y);
	if(--n == 0) exit(0);
}
int main() {
	std::cin >> n;
	write(0, 0);
	for(int i = 1;;++i) write(i, 0), write(0, i), write(-i, 0), write(0, -i);
}