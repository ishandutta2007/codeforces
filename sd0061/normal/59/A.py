S = raw_input()
l = len(filter(lambda c: ord('A') <= ord(c) <= ord('Z') , S))
if l > len(S) - l:
    print S.upper()
else:
    print S.lower()