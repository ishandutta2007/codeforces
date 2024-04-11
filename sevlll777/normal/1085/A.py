s = input()
kl = ""
dd = len(s) % 2
if dd:
    while len(s) > 1:
        kl = s[0] + kl
        kl = s[-1] + kl
        s = s[1:-1]
    print(s[0] + kl)
else:
    while len(s) > 1:
        kl = s[-1] + kl
        kl = s[0] + kl
        s = s[1:-1]
    print(kl)