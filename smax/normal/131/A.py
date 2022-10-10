s = input()
if s.isupper():
    print(s.lower())
elif len(s) == 1:
    print(s.upper())
elif s[1:].isupper():
    print(s[0].upper() + s[1:].lower())
else:
    print(s)