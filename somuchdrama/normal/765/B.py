s = input()
w = [15234562] * 27
cnt = 0
for i in range(len(s)):
	if w[ord(s[i]) - ord('a')] == 15234562:
		w[ord(s[i]) - ord('a')] = i
		cnt += 1
for i in range(cnt):
	if w[i] >= w[i + 1]:
		print("NO")
		exit(0)
print("YES")