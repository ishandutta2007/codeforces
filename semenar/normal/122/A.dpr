program Happiness;
var number, i: integer;
happy_numbers: array [1..14] of integer;
ans: string;
begin
  readln(number);
  ans:='NO';
  happy_numbers[1]:=4;
  happy_numbers[2]:=7;
  happy_numbers[3]:=44;
  happy_numbers[4]:=47;
  happy_numbers[5]:=74;
  happy_numbers[6]:=77;
  happy_numbers[7]:=444;
  happy_numbers[8]:=447;
  happy_numbers[9]:=474;
  happy_numbers[10]:=477;
  happy_numbers[11]:=744;
  happy_numbers[12]:=747;
  happy_numbers[13]:=774;
  happy_numbers[14]:=777;
  for i:=1 to 14 do
    if ((number mod happy_numbers[i]) = 0) then ans := 'YES';
  writeln(ans);
end.