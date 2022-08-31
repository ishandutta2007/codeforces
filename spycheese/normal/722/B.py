n = int(input())
a = map(int, input().split())
for w in a:
	s = input()
	if w != sum(s.count(c) for c in "aeiouy"):
		print("NO")
		exit(0)
print("YES")