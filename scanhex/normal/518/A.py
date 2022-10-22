s, t = input(), input()
for i in range(len(s)):
    if s[i] < 'z' and s[:i] + chr(ord(s[i]) + 1) + s[i + 1:] < t:
        print(s[:i] + chr(ord(s[i]) + 1) + s[i + 1:])
        exit(0)
    if t[i] > 'a' and t[:i] + chr(ord(t[i]) - 1) + t[i + 1:] > s:
        print(t[:i] + chr(ord(t[i]) - 1) + t[i + 1:])
        exit(0)
print('No such string')