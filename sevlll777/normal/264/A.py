s = input()
ans = [0] * len(s)
left = 0
right = len(s) - 1
for i in range(len(s)):
    if s[i] == 'r':
        ans[left] = i+1
        left += 1
    else:
        ans[right] = i+1
        right -= 1
print(*list(ans))