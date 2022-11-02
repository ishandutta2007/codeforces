function trim(s) {
    return s.replace(/^\s+|\s+$/gm, '');
}

function tokenize(s) {
    return trim(s).split(/\s+/);
}

function tokenizeIntegers(s) {
    var tokens = tokenize(s);
    for (var i = 0; i < tokens.length; i += 1) {
        tokens[i] = parseInt(tokens[i]);
    };
    return tokens;
}

function main() {
    var integers = tokenizeIntegers(readline());
    var A = integers[0], B = integers[1];
    print(A + B);
}

main();