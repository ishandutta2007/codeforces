d = {'q':-9,'r':-5,'b':-3,'n':-3,'p':-1,
    'Q':9,'R':5,'B':3,'N':3,'P':1}

t = sum(sum((d[c] if c in d else 0) for c in raw_input()) for x in range(8))
print ("White" if t > 0 else ("Black" if t < 0 else "Draw"))