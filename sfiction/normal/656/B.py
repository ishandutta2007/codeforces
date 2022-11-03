n = int(raw_input())
m = map(int, raw_input().split())
r = map(int, raw_input().split())

S = 16 * 9 * 5 * 7 * 11 * 13
cnt = 0
for i in range(S):
	t = 0
	for j in range(n):
		if i % m[j] == r[j]:
			t = 1;
			break
	cnt += t
		
print cnt / float(S)