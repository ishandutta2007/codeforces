s = input()
if len(set(s)) == 1:
    print(0)
elif s[::-1] == s:
    print(len(s) - 1)
else:
    print(len(s))