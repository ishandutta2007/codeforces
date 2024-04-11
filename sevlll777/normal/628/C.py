n, k = map(int, input().split())
s = input()
new = ''
for i in range(n):
    if k > max(ord(s[i]) - ord('a'), ord('z') - ord(s[i])):
        if ord(s[i]) - ord('a') > ord('z') - ord(s[i]):
            new += 'a'
            k -= ord(s[i]) - ord('a')
        else:
            new += 'z'
            k -= ord('z') - ord(s[i])
    else:
        if chr(ord(s[i]) + k) <= 'z':
            new += chr(ord(s[i]) + k)
        else:
            new += chr(ord(s[i]) - k)
        k = 0
        new += s[i+1:]
        break
if k == 0:
    print(new)
else:
    print(-1)